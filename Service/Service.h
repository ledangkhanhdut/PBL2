#include <string>
using namespace std;

class Service
{
public:
    unsigned int id ;
    string name;
    unsigned int money; 
public:
    Service(unsigned int = 999 , const string & ="" ,  unsigned int = 0 );
    Service(const Service &);
    ~Service();
};

