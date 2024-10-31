
#include "Account.h"

#define file_Acc "account.txt"

bool Account::Login(const string &User, const string &Pass)
{
    ifstream in_file(file_Acc);
    int Size, tmp_Id, tmp = 0, tmp_Role;
    in_file >> Size;
    Account *List_Acc = new Account[Size];
    string tmp_User, tmp_Pass;
    while (in_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc[tmp] = Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role);
        ++tmp;
    }
    in_file.close();
    for (int i = 0; i < Size; i++)
        if (List_Acc[i].Compare(User, Pass))
        {
            (*this) = List_Acc[i];
            return true;
        }
    delete[] List_Acc;
    return false;
}

Account::Account(const int &id, const string &name, const string &pass, int role)
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
bool Account::Register(const string &username, const string &pass, int role)
{
    ifstream in_file(file_Acc);
    int Size, tmp_Id, tmp_Role, tmp = 0;
    in_file >> Size;
    vector<Account> List_Acc;
    string tmp_User, tmp_Pass;
    Account new_Acc;
    
    while (in_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc.push_back(Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role)); // Thêm vào vector
        if (tmp_User == username)
            return false; // Trả về false nếu username đã tồn tại
    }
    in_file.close();

    // Them tai khoan moi vao vecto
    for (int i = 1; i < Size; i++)
        if (List_Acc[i].ID - List_Acc[i - 1].ID != 1)
        {
            tmp = i;
            break;
        }
    
    if (tmp == 0) List_Acc.push_back(Account(List_Acc.back().get_Id() + 1, username, pass, role));
    else {
         new_Acc = Account(List_Acc[tmp].ID - 1, username,pass,role);
         List_Acc.insert(List_Acc.begin() + tmp,new_Acc);
        }
    Size++;
    ofstream out_file(file_Acc);
    out_file << Size << std::endl;
    for (const auto &acc : List_Acc)
        out_file << acc.ID << " " << acc.Username << " " << acc.Pass << " " << acc.Role << std::endl;
    out_file.close();

    return true;
}

void Account::Change_Pass(const string &Pass)
{
    string NewPass;
    cout << "Nhap NewPass:";
    cin >> NewPass;
    this->Pass = NewPass;
}
bool Account::Compare(const string &User, const string &Pass)
{
    return (((this->Username == User) && (this->Pass == Pass)));
}

bool Account::Remove_Acc(const string &user)
{
    ifstream in_file(file_Acc);
    int Size, tmp_Id, tmp_Role, tmp = 0, tmp_2 = -1;
    in_file >> Size;
    vector<Account> List_Acc;
    string tmp_User, tmp_Pass;

    while (in_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc.push_back(Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role));
        if (tmp_User == user)
        {
            tmp_2 = tmp;
        }
        ++tmp;
    }
    in_file.close();

    if (tmp_2 == -1)
        return 0;
    List_Acc.erase(List_Acc.begin() + tmp_2);

    ofstream out_file(file_Acc);
    --Size;
    out_file << Size << endl;
    for (int i = 0; i < Size; i++)
        out_file << List_Acc[i].ID << " " << List_Acc[i].Username << " " << List_Acc[i].Pass << " " << List_Acc[i].Role << endl;
    out_file.close();
    return 1;
}
int Account::get_Id()
{
    return this->ID;
}
int Account::get_Role()
{
    return this->Role;
}
Account::~Account()
{
}
