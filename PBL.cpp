#include "Person.h"
#include "Account.h"
#include "vector"

#define file_doctor "doctor.txt"

class Manager : public Account : public Account
{
public:
    void change_Doctor();
    void Add_Doctor();
    void Remove_Doctor();
    void change_Cashier();
    void change_Patient();
    ~Manager();
};
void Manager::Add_Doctor()
{
}
void Manager::Remove_Doctor()
{
}
void Manager::change_Doctor()
{
    int tmp;
    do
    {
        cout << "Chon yeu cau cua ban." << endl;
        cout << "1. Them Bac Si." << endl;
        cout << "2. Xoa Bac Si." << endl;
        cout << "3. Exit." << end;
        cout << "Hay nhap yeu cau cua ban:";
        cin >> tmp;
        if (tmp == 1)
            Add_Doctor();
        if (tmp == 2)
            Remove_Doctor();
    } while (tmp != 3)
}

void Manager::change_Cashier()
{
}

void Manager::change_Patient()
{
}
Manager::~Manager()
{
}
class Doctor : public Person
{
private:
    string Time_Working;
    string Exp;

public:
    Doctor(string = " ", string = " ");
    Doctor(const Doctor &);
    void view_Workschedule();
    void view_Patient();
    void add_Medical();
    ~Doctor();
};
Doctor::Doctor(string Time_K, string Exp)
{
    this->Time_Working = Time_Woking;
    this->Exp = Exp;
}
Doctor::Doctor(const Doctor &p)
{
    this->Time_Working = p.Time_Working;
    this->Exp = p.Exp;
}
void Doctor::view_Workschedule()
{
}
void Doctor::view_Patient()
{
}
void Doctor::add_Medical()
{
}
Doctor::~Doctor() {};

Doctor Tachchuoi(const string &line)
{
    Doctor p1.
}

int main()
{
    Doctor p1;
}