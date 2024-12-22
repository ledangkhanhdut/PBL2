#include "Person.h"

class Patient : public Person
{
public:
    Patient(unsigned int = 9999 , const string & = "", int = 0, const string & = "", const string & = "", char = ' ');
    Patient(const Patient &);
    void update_information(const Patient &);
    ~Patient();
};



