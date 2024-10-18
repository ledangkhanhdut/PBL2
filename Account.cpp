
#include "Account.h"

#define file_Acc "account.txt"

int Check_Acc(const string &User, const string &Pass)
{
    ifstream tmp_file(file_Acc);
    int Size, tmp_Id, tmp = 0;
    tmp_file >> Size;
    Account *List_Acc = new Account[Size];
    string tmp_User, tmp_Pass;

    char tmp_Role;
    while (tmp_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc[tmp] = Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role);
        ++tmp;
    }
    tmp_file.close();
    for (int i = 0; i < Size; i++)
        if (List_Acc[i].Compare(User, Pass))
        {
            tmp_Id = List_Acc[i].get_Id();
            delete[] List_Acc;
            return (tmp_Id);
        }
    delete[] List_Acc;
    return 0;
}

Account::Account(const int &id, const string &name, const string &pass, char role)
{
    this->ID = id;
    this->Username = name;
    this->Pass = pass;
    this->Role = role;
}
Account::Account(const Account &p)
{
    this->ID = p.ID;
    this->Username = p.Username;
    this->Pass = p.Pass;
    this->Role = p.Role;
}

bool Account::Register(const string &username, const string &pass, char role)
{
    ifstream tmp_file(file_Acc);
    int Size, tmp_Id, tmp = 0;
    tmp_file >> Size;
    Account *List_Acc = new Account[Size + 1];
    string tmp_User, tmp_Pass;
    char tmp_Role;
    while (tmp_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc[tmp] = Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role);
        if (tmp_User == username)
            return false;
        ++tmp;
    }
    List_Acc[Size] = Account(List_Acc[Size - 1].get_Id() + 1, username, pass, role);
    Size++;
    tmp_file.close();

    ofstream tmp1_file(file_Acc);
    tmp1_file << Size << endl;
    for (int i = 0; i < Size; i++)
        tmp1_file << List_Acc[i].ID << " " << List_Acc[i].Username << " " << List_Acc[i].Pass << " " << List_Acc[i].Role << endl;
    tmp1_file.close();
    delete[] List_Acc;
    return true;
}

int Account::Login()
{
    string tmp_Username, tmp_Pass;

    cout << "UserName: ";
    cin >> tmp_Username;

    cout << "Pass: ";
    cin >> tmp_Pass;
    return Check_Acc(tmp_Username, tmp_Pass);
}
void Account::Change_Pass(const string &Pass)
{
    string NewPass;
    cout << "NewPass:";
    cin >> NewPass;
    this->Pass = NewPass;
}
bool Account::Compare(const string &User, const string &Pass)
{
    return (((this->Username == User) && (this->Pass == Pass)));
}

int Account::get_Id()
{
    return this->ID;
}
Account::~Account()
{
}
