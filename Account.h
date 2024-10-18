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
  char Role;

public:
  Account(const int & = -1, const string & = "", const string & = "", char = 'P');
  Account(const Account &);
  bool Register(const string &, const string &, char);
  int Login();
  void Change_Pass(const string &);
  bool Compare(const string &, const string &);
  int get_Id();
  ~Account();
};
