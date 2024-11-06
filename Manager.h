#include "Account.h"
#include <iostream>
using namespace std;

class Manager : public Account 
{
public:
    Manager(const Account &);
    bool Add_Doctor(const string &,const string &);
    bool Remove_Doctor(const string&);
    bool Add_Cashier(const string &);
    bool Remove_Cashier(const string & );
    bool Add_Patient(const string &,const string &);
    bool Remove_Patient(const string & );
    ~Manager();
};