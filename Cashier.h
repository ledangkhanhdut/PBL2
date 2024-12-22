#include "Person.h"

class Cashier : public Person
{
public:
    Cashier(unsigned int = 9999 , const string & = "", int = 0, const string & = "", const string & = "", char = ' ');
    Cashier(const Cashier &);
    ~Cashier();
};



