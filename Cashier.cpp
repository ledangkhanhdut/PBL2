#include "Cashier.h"


Cashier::Cashier(unsigned int Id,const string &name, int age, const string &phone, const string &address, char gender) : Person(Id,name,age,phone,address,gender)
{
}
Cashier::Cashier(const Cashier &p) : Person(p)
{
}

Cashier::~Cashier()
{
    
}