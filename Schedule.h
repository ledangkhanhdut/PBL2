#include <string>
#include <iostream>
using  namespace std;


class Schedule
{
public:
    string Time_w;
    unsigned int Id_patient;
    string Name_Patient;
    string Combo;
    string Medical;
    string About;
    char Status;
public:
    Schedule(const string & = "0", unsigned  int = 0, const string & = "0", const string & = "0", const string & = "0", const string & = "0", char = 'N');
    Schedule(const  Schedule &);
    void Change_Status();
    ~Schedule();
};


