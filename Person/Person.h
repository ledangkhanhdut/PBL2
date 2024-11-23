#ifndef PERSON_H  /*Tranh nap nhieu lan trong 1 file */
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
    unsigned int Id;
    string Name;
    int age;
    string Phone_Number;
    string address;
    char gender;
public:
    Person(unsigned int Id = 9999, const string & = "", int = 0, const string & = "", const string & = "", char = 'B');
    Person(const Person &);
    // void update_Information(const Person &);
    void set_Id(const unsigned int & );
    unsigned int get_ID() const;
    string get_Name() const;
    void set_Name(const string &);
    int get_Age() const;
    void set_Age(int);
    string  get_Phone_Number() const;
    void  set_Phone_Number(const string &);
    string  get_Address() const ;
    void  set_Address(const string &);
    char get_Gender() const;
    void   set_Gender(const char &);
    ~Person();
};


#endif