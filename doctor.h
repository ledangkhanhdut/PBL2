#include "Person.h"
#include "Account.h"
#include <string>

class Doctor : public Person
{
private:
    string Time_Working;
    string Exp;

public:
    Doctor(unsigned int  ,const string & = "", int = 0, const string & ="", const string & ="", char = ' ', const string & = "", const string & = "");
    Doctor(const Doctor &);
    void view_Workschedule();
    void view_Patient();
    void add_Medical();
    ~Doctor();
};