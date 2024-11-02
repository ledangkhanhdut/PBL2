#include "Manager.h"

Manager::Manager(const Account &p):Account(p){
}

bool Manager::Add_Doctor(const string  &user, const string &pass)
{   Account new_Acc;
    string file;
    bool check = new_Acc.Register(user,pass,2);
    if (check){
    file = "Doctor/chedule/"+to_string(new_Acc.get_Id())+".txt";
    // Tao file lam viec moi cho bac si
    ofstream new_file(file);
    new_file.close();

    // Tao file chua thong tin bac si 
    file = "Doctor/Information_doctor/"+to_string(new_Acc.get_Id())+".txt";
    ofstream new_file2(file);
    new_file2.close();
    }
    return (check);
}
bool Manager::Remove_Doctor(const string &user)
{
    Account tmp_Acc;
    return tmp_Acc.Remove_Acc(user);
}
bool Manager::Add_Cashier(const string &id){

}
bool Manager::Remove_Cashier(const string &id){
     
}
bool Manager::Add_Patient(const string &user,const string &pass){
    Account new_Acc;
    return (new_Acc.Register(user,pass,4));
}
bool Manager::Remove_Patient(const string &user)
{
    Account tmp_Acc;
    return tmp_Acc.Remove_Acc(user);
}
Manager::~Manager()
{
}