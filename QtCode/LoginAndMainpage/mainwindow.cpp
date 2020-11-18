#include "mainwindow.h"
#include "signupwindow.h"
#include "loginwindow.h"
#include "ui_mainwindow.h"
#include "LoginInfo.h"
#include "tools.h"

#include <QtSql>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Memerior");

    QPixmap pixmap("./images/bg_resize.jpg"); //设定图片
    QPalette palette;                         //创建一个调色板对象
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);         //设置窗口调色板为palette，窗口和画笔相关联
    setAutoFillBackground(true); //设置窗体自动填充背景

    connect(ui->signButton, SIGNAL(clicked()), this, SLOT(openSignUp()));
    connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(openLogin()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSignUp()
{
    SignUpWindow *signUp = new SignUpWindow(this);
    connect(signUp, SIGNAL(sendLoginInfo(QString, int)), this, SLOT(receiveLoginInfo(QString, int)));
    signUp->show();
}

void MainWindow::openLogin()
{
    LoginWindow *login = new LoginWindow(this);
    connect(login, SIGNAL(sendLoginInfo(QString, int)), this, SLOT(receiveLoginInfo(QString, int)));
    login->show();
}

void MainWindow::receiveLoginInfo(QString username, int accountId)
{

    QString session = getRandomString(32);
    qint64 expireAt = QDateTime::currentDateTime().toSecsSinceEpoch() + 7 * 24 * 60 * 60;

    // file
    LoginInfo::setLoginInfo(accountId, username, session);
    LoginInfo::saveLoginInfo();

    // session
    QSqlQuery query;
    QString sqlQuery = QString("SELECT * FROM account_session WHERE account_id = %1").arg(accountId);
    qDebug() << "Generated sql: " << sqlQuery;
    if (!query.exec(sqlQuery))
        qDebug() << "Query Error: " << query.lastError().driverText();
    if (query.next())
    {
        QSqlQuery update;
        QString sqlUpdate = QString("Update account_session SET id='%1', expire_at=%2 WHERE account_id = %3")
                                .arg(session)
                                .arg(expireAt)
                                .arg(accountId);
        qDebug() << "Generated sql: " << sqlUpdate;
        if (!update.exec(sqlUpdate))
            qDebug() << "Query Error: " << query.lastError().driverText();
    }
    else
    {
        QSqlQuery update;
        QString sqlUpdate = QString("INSERT INTO account_session SET id='%1', expire_at=%2, account_id=%3")
                                .arg(session)
                                .arg(expireAt)
                                .arg(accountId);
        qDebug() << "Generated sql: " << sqlUpdate;
        if (!update.exec(sqlUpdate))
            qDebug() << "Query Error: " << query.lastError().driverText();
    }

    // log
    InsertLog(accountId, "Log In");
}

void MainWindow::directLogin()
{
    int id = 0;
    uint expireAt = 0;
    bool hasError = false;
    QSqlQuery query;
    QString sqlQuery = QString("SELECT * FROM account_session WHERE id = '%1'").arg(LoginInfo::getSession());
    qDebug() << "Generated sql: " << sqlQuery;
    if (!query.exec(sqlQuery))
        qDebug() << "Query Error: " << query.lastError().driverText();
    if (query.next())
    {
        expireAt = query.value(query.record().indexOf("expire_at")).toUInt();
        id = query.value(query.record().indexOf("account_id")).toInt();
    }
    else hasError = true;
    
    if (id != LoginInfo::getId()) hasError = true;
    if (expireAt < QDateTime::currentDateTime().toSecsSinceEpoch()) hasError = true;
    
    if (hasError)
        if (!(QMessageBox::warning(this, tr("Auto Login Fail"), tr("Your login infomation is invalid or already expired, please login again."), tr("Ok"))))
            LoginInfo::cleanLoginInfo();
    else 
        InsertLog(id, "Direct Log In");
}
