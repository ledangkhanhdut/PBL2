#include <string>
#include <iostream>
using namespace std;

class Medical
{
public:
   string Name;
   unsigned int Money;
public:
    Medical(const string & ="0", unsigned int = 0 );
    Medical(const  Medical &);

    ~Medical();
};
