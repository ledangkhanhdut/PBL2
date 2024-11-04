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

// void Person::update_Information(const Person &p)
// {
//     this->Id = p.Id;
//     this->Name = p.Name;
//     this->age = p.age;
//     this->Phone_Number = p.Phone_Number;
//     this->address = p.address;
//     this->gender = p.gender;
// }
void Person::set_Id(const unsigned int & id){
    this->Id  = id;
}
unsigned int  Person::get_ID() const {
    return this->Id;
}
string  Person::get_Name() const {
    return this->Name;
}
void  Person::set_Name(const string & name){
    this->Name =  name;
}
int get_Age() const {
    return this->age;
}
void set_Age(int age){
    this->age  = age;
}


string   Person::get_Phone_Number() const {
    return this->Phone_Number;
}
void   Person::set_Phone_Number(const string & phone){
    this->Phone_Number = phone;
}
string Person::get_Address() const {
    return this->address;
}
void Person::set_Address(const string & address) {
    this->address = address;
}
char  Person::get_Gender() const {
    return this->gender;
}
void Person::set_Gender(const char &gender){
    this->address = address;
}
Person::~Person(){
}
