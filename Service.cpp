#include "Service.h"

Service::Service(unsigned int  id, const std::string& name, unsigned int money)
{
    this->id = id;
    this->name = name;
    this->money = money;
}
Service::Service(const Service & p){
    this->id = p.id;
    this->name = p.name;
    this->money = p.money;
}
Service::~Service()
{
}
