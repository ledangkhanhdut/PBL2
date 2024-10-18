#include "Person.h"

Person::Person(const string &name, int age, const string &phone, const string &address, char gender)
{
    this->name = name;
    this->age = age;
    this->Phone_Number = phone;
    this->address = address;
    this->gender = gender;
}
Person::Person(const Person &p)
{
    this->name = p.name;
    this->age = p.age;
    this->Phone_Number = p.Phone_Number;
    this->address = p.address;
    this->gender = p.gender;
}

void Person::update_Infomation(const Person &p)
{
    this->name = p.name;
    this->age = p.age;
    this->Phone_Number = p.Phone_Number;
    this->address = p.address;
    this->gender = p.gender;
}
Person::~Person()
{
}