#include "Person.h"
#include <string>

class Doctor : public Person
{
private:
    string Exp;

public:
    Doctor(unsigned int = 9999 ,const string & = "", int = 0, const string & ="", const string & ="", char = ' ', const string & = "");
    Doctor(const Doctor &);
    void view_Workschedule();
    void view_Patient();
    void add_Medical();
    string get_Exp() const ;
    void  set_Exp(const string &);
    ~Doctor();
};