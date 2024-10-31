#include "Person.h"

Person::Person(unsigned int Id,const string &name, int age, const string &phone, const string &address, char gender)
{   
    this->Id = Id;
    this->Name = Name;
    this->age = age;
    this->Phone_Number = phone;
    this->address = address;
    this->gender = gender;
}

Person::Person(const Person &p)
{   
    this->Id = p.Id;
    this->Name = p.Name;
    this->age = p.age;
    this->Phone_Number = p.Phone_Number;
    this->address = p.address;
    this->gender = p.gender;
}

void Person::update_Information(const Person &p)
{
    this->Id = p.Id;
    this->Name = p.Name;
    this->age = p.age;
    this->Phone_Number = p.Phone_Number;
    this->address = p.address;
    this->gender = p.gender;
}
Person::~Person(){
}
