#include "Medical.h"

Medical::Medical(const string &name, unsigned int money) : Name(name), Money(money) {}

Medical::Medical(const Medical &p){
    this->Name = p.Name;
    this->Money = p.Money;
}

Medical::~Medical()
{
}
