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
    Person(unsigned int Id, const string & = "", int = 0, const string & = "", const string & = "", char = ' ');
    Person(const Person &);
    void update_Information(const Person &);
    ~Person();
};
