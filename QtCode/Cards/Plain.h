#ifndef Plain_H_
#define Plain_H_

#include "Card.h"


class Plain: public Card{
private:
    QString ans;

public:
	Plain();
	~Plain();
    virtual QString add_display(int) const;
    virtual QString option(int id =0 , QString str="");
};

#endif /* Plain_H_ */
