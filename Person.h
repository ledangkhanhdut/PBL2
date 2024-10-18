#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
    string Name;
    int age;
    string Phone_Number;
    string address;
    char gender;

public:
    Person(const string &name, int age, const string &phone, const string &address, char gender);
    Person(const Person &);
    void update_Infomation(const Person &);
    ~Person();
};
