#include "Manager.h"

Manager::Manager(const Account &p):Account(p){
}

bool Manager::Add_Doctor(const string  &user, const string &pass)
{   Account new_Acc;
    return (new_Acc.Register(user,pass,2));
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