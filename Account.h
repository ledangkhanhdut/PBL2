#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Account
{
private:
  int ID;
  string Username;
  string Pass;
  int Role;

public:
  Account(const int & = -1, const string & = "", const string & = "", int = 4);
  Account(const Account &);
  bool Register(const string &, const string &, int);
  bool Login(const string &, const string &);
  bool Compare(const string &, const string &);
  bool Remove_Acc(const string &,int role);
  unsigned int get_Id() const ;
  int get_Role();
  string get_Pass() const;
  void Set_Pass(const string &);
  void Change_Pass();
  ~Account();
};
