
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
// int binarySearchDiscrepancy(vector<Account>& List_Acc, int Size) {
//     int left = 1;
//     int right = Size - 1;
    
//     while (left <= right) {
//         int mid = left + (right - left) / 2;

//         if (List_Acc[mid].ID - List_Acc[mid - 1].ID != 1) {
//             return mid;
//         } else {
//             if (List_Acc[mid].ID - List_Acc[mid - 1].ID == 1) {
//                 left = mid + 1;
//             }
//         }
//     }
//     return -1;
// }

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


 
    if (tmp == 0)
    {
        List_Acc.push_back(Account(List_Acc.back().get_Id() + 1, username, pass, role));
        (*this) = List_Acc[Size];
    }
    else
    {
        new_Acc = Account(List_Acc[tmp].ID - 1, username, pass, role);
        (*this) = new_Acc;
        List_Acc.insert(List_Acc.begin() + tmp, new_Acc);
    }

    Size++;
    ofstream out_file(file_Acc);
    out_file << Size << std::endl;
    for (const auto &acc : List_Acc)
        out_file << acc.ID << " " << acc.Username << " " << acc.Pass << " " << acc.Role << endl;
    out_file.close();

    return true;
}

void Account::Set_Pass(const string &Pass)
{
    this->Pass = Pass;
}
bool Account::Compare(const string &User, const string &Pass)
{
    return (((this->Username == User) && (this->Pass == Pass)));
}

bool Account::Remove_Acc(const string &user,int role)
{
    ifstream in_file(file_Acc);
    int Size, tmp_Id, tmp_Role, tmp = 0, tmp_2 = -1;
    in_file >> Size;
    vector<Account> List_Acc;
    string tmp_User, tmp_Pass;

    while (in_file >> tmp_Id >> tmp_User >> tmp_Pass >> tmp_Role)
    {
        List_Acc.push_back(Account(tmp_Id, tmp_User, tmp_Pass, tmp_Role));
        if (tmp_User == user && role == tmp_Role)
        {
            tmp_2 = tmp;
        }
        ++tmp;
    }
    in_file.close();

    if (tmp_2 == -1)
        return 0;
     /*(*this) tra ve id cho manager */   
    (*this) = List_Acc[tmp_2];
    List_Acc.erase(List_Acc.begin() + tmp_2);

    ofstream out_file(file_Acc);
    --Size;
    out_file << Size << endl;
    for (int i = 0; i < Size; i++)
        out_file << List_Acc[i].ID << " " << List_Acc[i].Username << " " << List_Acc[i].Pass << " " << List_Acc[i].Role << endl;
    out_file.close();
    return 1;
}
unsigned Account::get_Id() const
{
    return this->ID;
}
int Account::get_Role()
{
    return this->Role;
}
string Account::get_Pass() const
{
    return this->Pass;
}
void Account::Change_Pass()
{
    ifstream file(file_Acc);
    int Size;
    file >> Size;
    Account List_Acc[Size];
    for (int i = 0; i < Size; i++)
    {
        file >> List_Acc[i].ID >> List_Acc[i].Username >> List_Acc[i].Pass >> List_Acc[i].Role;
        if (this->ID == List_Acc[i].ID)
        {
            List_Acc[i].Pass = this->Pass;
        }
    }

    ofstream out_file(file_Acc);
    out_file << Size << endl;
    for (int i = 0; i < Size; i++)
        out_file << List_Acc[i].ID << " " << List_Acc[i].Username << " " << List_Acc[i].Pass << " " << List_Acc[i].Role << endl;
    out_file.close();
}
Account::~Account()
{
}
