// #include "Person.h"
#include "Manager.h"
#include "doctor.h"
// #include "Patient.h"
#include <string>
void Home();
void Login();
void Register();
void Management_interface(Account &);
void Doctor_Workspace(Account &);
void Add_Doctor(Manager &);
void Add_Cashier(Manager &);
void Add_Patient(Manager &);
void Remove_Doctor(Manager &);
void Remove_Cashier(Manager &);
void Remove_Patient(Manager &);

void Register()
{
    Account tmp;
    string user, pass;
    bool check;
    do
    {
        cout << "Tai Khoan:";
        cin >> user;
        cout << "Mat khau: ";
        cin >> pass;
        check = tmp.Register(user, pass, 4);
        if (check == false)
            cout << "Tai khoan da ton tai" << endl;
    } while (check == false);
    cout << "Tao tai khoan thanh cong." << endl;
}
void Login()
{
    Account tmp;
    string user, pass;
    bool check;
    {
        cout << "Tai Khoan:";
        cin >> user;
        cout << "Mat khau: ";
        cin >> pass;
        check = tmp.Login(user, pass);
        if (check == false)
            cout << "Tai khoan hoac mat khau khong hop le." << endl;
    }
    while (check == false)
        ;
    switch (tmp.get_Role())
    {
    case 1:
        Management_interface(tmp);
        break;
    case 2:
        break;
        Doctor_Workspace(tmp);
    case 3:
        break;
    default:
        break;
    }
}
void Management_interface(Account &Acc)
{
    int choice;
    do
    {
        Manager Admin(Acc);
        cout << "1.Them Bác Sĩ" << endl;
        cout << "2.Xóa Bác Sĩ" << endl;
        cout << "3.Them Thu Ngan" << endl;
        cout << "4.Xóa Thu Ngan" << endl;
        cout << "5.Them benh nhan" << endl;
        cout << "6.Xóa benh nhan" << endl;
        cout << " 7.Thoat" << endl;
        cout << "Hay nhap yeu cau cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Add_Doctor(Admin);
            break;
        case 2:
            Remove_Doctor(Admin);
            break;
        case 3:
            Add_Cashier(Admin);
            break;
        case 4:
            Remove_Cashier(Admin);
            break;
        case 5:
            Add_Patient(Admin);
            break;
        case 6:
            Remove_Patient(Admin);
            break;
        case 7:
            break;
        default:
             cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }
    } while (choice != 7);
}
void Add_Doctor(Manager &Admin)
{
    string user, pass;
    cout << "Tai khoan: ";
    cin >> user;
    cout << "Mat khau: ";
    cin >> pass;
    if (Admin.Add_Doctor(user, pass) == true)
        cout << "Tao tai khoan thanh cong";
    else
        cout << "Tao tai khoan that bai";
}
void Remove_Doctor(Manager &Admin)
{
    string user;
    bool check;
    do
    {
        cout << "Nhap tai khoan can xoa: ";
        cin >> user;
        check = Admin.Remove_Doctor(user);
        if (check)
            cout << "Xoa tai khoan thanh cong";
        else
            cout << "Xoa tai khoan that bai";
    } while (check = false);
}

void Add_Cashier(Manager &Admin)
{
}
void Add_Patient(Manager &Admin)
{
    string user, pass;
    cout << "Tai khoan: ";
    cin >> user;
    cout << "Mat khau: ";
    cin >> pass;
    if (Admin.Add_Patient(user, pass) == true)
        cout << "Tao tai khoan thanh cong";
    else
        cout << "Tao tai khoan that bai";
}
void Remove_Cashier(Manager &Admin)
{
}
void Remove_Patient(Manager &Admin)
{
    string user;
    bool check;
    do
    {
        cout << "Nhap tai khoan can xoa: ";
        cin >> user;
        check = Admin.Remove_Patient(user);
        if (check)
            cout << "Xoa tai khoan thanh cong";
        else
            cout << "Xoa tai khoan that bai";
    } while (check = false);
}

void Doctor_Workspace(Account &acc)
{
    int choice;
    Doctor tmp;
    tmp.set_Id(acc.get_Id());
    cout << "1.Sua thong tin ca nhan." << endl;
    cout << "2.Lich lam viec." << endl;
    cout << "3.Thoat." << endl;

    do
    {
        cout << "Nhap yeu cau cua ban.";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Change_Infomation_Doctor(tmp, acc);
            break;
        case 2:
            view_Workshedule(tmp);
            break;
        case 3:
            break;
        default:
               cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }

    } while (choice != 3);
}

void Change_Infomation_Doctor(Doctor &tmp, Account &acc)
{
    int choice = 0;
    do
    {
        cout << "1.Doi mat khau." << endl;
        cout << "2.Cap nhat ho va ten ." << endl;
        cout << "3.Cap nhat ngay sinh. " << endl;
        cout << "4.Cap nhat gioi tinh." << endl;
        cout << "5.Cap nhat so dien thoai." << endl;
        cout << "6.Cap nhat email." << endl;
        cout << "7.Cap nhat kinh nghiem" << endl;
        cout << "8.Cap nhat thoi gian lam viec." << endl;
        cout << "9.Thoat." << endl;
        cout << "Hay nhap yeu cau cua ban:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            change_Password_Doctor(acc);
            break;
        case 2:
            update_Name(tmp);
            break;
        case 3:
            // update_Birthday(tmp);
            break;
        case 4:
            // update_Gender(tmp);
            break;
        case 5:
            // update_Phone(tmp);
            break;
        case 6:
            // update_Email(tmp);
            break;
        case 7:
            // update_Experience(tmp);
            break;
        case 8:
            // update_Time_Woking(tmp);
            break;
        case 9:
            break;
        default:
            cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }

    } while (choice != 9);
}
void  change_Password_Doctor(Account &acc){
    string  old_password, new_password;
    bool check = true;
    do{
    cout <<"Nhap mat khau cu: ";
    cin >>  old_password;
    cout <<"Nhat mat khau moi: ";
    cin  >> new_password;
    check = (old_password != acc.get_Pass());
    if (check)
        cout << "Mat khau dang nhap khong chinh xac." <<endl;  else
        {
            acc.Set_Pass(new_password);
        }
    } while(check);
}
void  update_Name(Doctor &tmp){
        string new_name;
       // cout << "Ten cu :" << 

}


void view_Workshedule(const Doctor &tmp)
{
}

void Home()
{
    int choice;
    do
    {
        cout << "Chao mung ban da chon chuc nang Home" << endl;
        cout << "1.Dang Ky" << endl;
        cout << "2.Dang Nhap" << endl;
        cout << "3. Thoat." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Register();
            break;

        case 2:
            Login();
            break;
        default:
            return;
            break;
        }
    } while (choice != 2);
}
int main()
{
    Home();
    return 0;
}
