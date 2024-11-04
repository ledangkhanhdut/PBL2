// #include "Person.h"
#include "Manager.h"
#include "doctor.h"
#include "Schedule.h"
#include "Medical.h"
// #include "Patient.h"
#include <string>
#include <chrono>
#include <iomanip>
#include <cstdlib>

#define Sokhunggio 7

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
void Change_Information_Doctor(Doctor &, Account &);
void change_Password_Doctor(Account &);

void update_Name(Doctor &);
void update_Gender(Doctor &);
void update_Phone(Doctor &);
void update_Address(Doctor &);
void update_Age(Doctor &);

void View_Schedule(const Doctor &);
void Show_Schedule(Schedule &);
void Change_About(Schedule &);
void Change_Medical(Schedule &);
void Design();
bool isNumeric(const string &);
// bool isValidDate(int, int, int);

int main()
{
    Design();
    Home();
    return 0;
}

void Home()
{
    int choice;
    do
    {
        cout << "Chao mung ban da chon chuc nang Home" << endl;
        cout << "1.Dang Ky" << endl;
        cout << "2.Dang Nhap" << endl;
        cout << "3.Thoat." << endl;
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

bool isNumeric(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

void getCurrentDate()
{
    auto now = std::chrono::system_clock::now();                      // Lấy thời gian hiện tại
    std::time_t now_time = std::chrono::system_clock::to_time_t(now); // Chuyển đổi thành time_t

    std::tm *ltm = std::localtime(&now_time);

    std::cout << "VD:Ngày hiện tại: "
              << std::put_time(ltm, "%d/%m/%Y") << std::endl; // Định dạng ngày tháng
}
// bool isValidDate(int day, int month, int year) {
//     if (month < 1 || month > 12) {
//         return false;
//     }

//     int daysInMonth;
//     switch (month) {
//         case 1: case 3: case 5: case 7: case 8: case 10: case 12:
//             daysInMonth = 31;
//             break;
//         case 4: case 6: case 9: case 11:
//             daysInMonth = 30;
//             break;
//         case 2:
//             if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//                 daysInMonth = 29;
//             } else {
//                 daysInMonth = 28;
//             }
//             break;
//         default:
//             return false;
//     }

//     return (day >= 1 && day <= daysInMonth);
// }
void Design()
{
}

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
    do
    {
        cout << "Tai Khoan: ";
        cin >> user;
        cout << "Mat khau: ";
        cin >> pass;

        check = tmp.Login(user, pass);

        if (!check)
        {
            cout << "Tai khoan hoac mat khau khong hop le." << endl;
        }
    } while (!check);

    switch (tmp.get_Role())
    {
    case 1:
        Management_interface(tmp);
        break;
    case 2:
        Doctor_Workspace(tmp);
        break;
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
    {
        cout << "Tao tai khoan thanh cong";
    }
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
    do
    {
        system("cls");
        cout << "1.Sua thong tin ca nhan." << endl;
        cout << "2.Lich lam viec." << endl;
        cout << "3.Thoat." << endl;
        cout << "Nhap yeu cau cua ban.";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Change_Information_Doctor(tmp, acc);
            break;
        case 2:
            View_Schedule(tmp);
            break;
        case 3:
            return;
            break;
        default:
            cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }
    } while (choice != 3);
}

void Change_Information_Doctor(Doctor &tmp, Account &acc)
{
    int choice = 0;
    do
    {
        cout << "1.Doi mat khau." << endl;
        cout << "2.Cap nhat ho va ten ." << endl;
        cout << "3.Cap nhat ngay sinh. " << endl;
        cout << "4.Cap nhat gioi tinh." << endl;
        cout << "5.Cap nhat so dien thoai." << endl;
        cout << "6.Cap nhat dia chi." << endl;
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
            update_Gender(tmp);
            break;
        case 5:
            update_Phone(tmp);
            break;
        case 6:
            update_Address(tmp);
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
void change_Password_Doctor(Account &acc)
{
    string old_password, new_password;
    bool check = true;
    do
    {
        cout << "Nhap mat khau cu: ";
        cin >> old_password;
        cout << "Nhat mat khau moi: ";
        cin >> new_password;
        check = (old_password != acc.get_Pass());
        if (check)
            cout << "Mat khau dang nhap khong chinh xac." << endl;
        else
        {
            acc.Set_Pass(new_password);
        }
    } while (check);
}

void update_Name(Doctor &tmp)
{
    string new_name, tmp_string = "";
    getline(cin, new_name);
    for (int i = 0; i < new_name.size(); i++)
        if (new_name[i] == ' ')
            tmp_string = tmp_string + new_name[i] + '-';
        else
            tmp_string = tmp_string + new_name[i];
    tmp_string.pop_back();
    tmp.set_Name(tmp_string);
}

void update_Gender(Doctor &tmp)
{
    int choice = 0;
    do
    {
        cout << "1.Nam" << endl;
        cout << "2.Nu" << endl;
        cout << "Nhap gioi tinh: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            tmp.set_Gender('B');
            break;
        case 2:
            tmp.set_Gender('G');
        default:
            cout << "Nhap sai!." << endl;
            break;
        }
    } while (choice != 1 || choice != 2);
}
void update_Age(Doctor &tmp)
{
    int choice, new_age;
    bool check = true;
    do
    {
        cout << "Tuoi hien tai : " << tmp.get_Age()<< endl;
        cout << "1.Thay doi tuoi." << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Nhap tuoi:";
                cin >> new_age;
                if (new_age > 20 && new_age < 100)
                {
                    check = true;
                    tmp.set_Age(new_age);
                }
                else
                {
                    check = false;
                    cout << "Tuoi khong hop le!" << endl;
                }
            } while (!check);
            break;
        case 2:
            return;
        default:
            cout << "Nhap sai xin hay nhap lai." << endl;
            break;
        }

    } while (choice != 2);
}
void update_Address(Doctor &tmp)
{
    string address;
    int choice;
    bool check = true;
    do
    {
        cout << "Dia chi hien tai : " << tmp.get_Address() << endl;
        cout << "1.Thay doi dai chi." << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap dia chi moi:";
            std::cin.ignore();
            getline(cin, address);
            tmp.set_Address(address);
            break;
        case 2:
            return;
        default:
            cout << "Nhap sai xin hay nhap lai." << endl;
            break;
        }

    } while (choice != 2);
}

void update_Phone(Doctor &tmp)
{
    string new_phone;
    int choice;
    bool check = true;
    do
    {
        cout << "So dien thoai hien tai:" << tmp.get_Phone_Number() << endl;
        cout << "1.Thay doi so dien thoai." << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Nhap so dien thoai moi:";
                cin >> new_phone;
                if (new_phone.size() == 10 && new_phone[0] == '0' && isNumeric(new_phone))
                {
                    check = true;
                    tmp.set_Phone_Number(new_phone);
                }
                else
                {
                    cout << "So dien thoai khong hop le." << endl;
                    check = false;
                }
            } while (!check);
            break;
        case 2:
            return;
        default:
            cout << "Nhap sai xin hay nhap lai." << endl;
            break;
        }

    } while (choice != 2);
}
void update_Experience(Doctor &tmp) {}
void update_Time_Woking(Doctor &tmp) {}

void View_Schedule(const Doctor &tmp)
{
    int STT = 0, choice = 0, choice2 = 0, A[Sokhunggio];
    Schedule List_Schedule[Sokhunggio];
    string date_m_y, line;
    string file_working = "Doctor/Schedule/" + to_string(tmp.get_ID()) + ".txt";
    ifstream file(file_working);
    if (!file)
    {
        cout << "File khong ton tai." << endl;
        return;
    }
    getCurrentDate();
    cout << "Chon ngay xem lich lam viec: ";
    cin >> date_m_y;

    file.clear();  // Đặt lại trạng thái của file
    file.seekg(0); // Di chuyển con trỏ về đầu file

    while (getline(file, line))
    {
        if (line == date_m_y)
            break;
    }
    if (line == "")
    {
        cout << "Khong co lich lam viec." << endl;
        return;
    }
    for (int i = 0; i < Sokhunggio; i++)
    {
        file >> List_Schedule[i].Time_w >> List_Schedule[i].Id_patient >> List_Schedule[i].Name_Patient >> List_Schedule[i].Combo >> List_Schedule[i].Medical >> List_Schedule[i].About >> List_Schedule[i].Status;
    }
    file.close();

    do
    {
        system("cls");
        cout << left << setw(5) << "STT" << setw(5) << "Time" << setw(20) << "Ten BN" << setw(10) << "Goi" << setw(5) << "Trang Thai" << endl;
        for (int i = 0; i < Sokhunggio; i++)
            if (List_Schedule[i].Id_patient != 0)
            {
                ++STT;
                A[STT] = i;
                cout << left << setw(5) << STT << setw(5) << List_Schedule[i].Time_w << setw(20) << List_Schedule[i].Name_Patient << setw(10) << List_Schedule[i].Combo << setw(5) << List_Schedule[i].Status << endl;
            }
        cout << "1.Chọn bệnh nhân cần xem." << endl;
        cout << "2.Tro lai." << endl;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                cout << "Nhap so thu tu benh nhan can xem: ";
                cin >> choice2;
                if (choice2 > STT || choice2 < 1)
                    cout << "STT khong ton tai:";
            } while (choice2 <= 0 || choice2 > STT);
            Show_Schedule(List_Schedule[A[choice2]]);
            STT = 0;
            break;
        case 2:
            /*Ghi lai vao file */
            return;
            break;
        default:
            cout << "Nhap sai, xin hay nhap lai.";
            break;
        }

    } while (choice != 2);
}

void Show_Schedule(Schedule &p)
{
    int choice;
    do
    {
        system("cls");
        // cout << setfill('-') << setw(70) << endl;
        cout << left << setw(10) << "Time" << setw(20) << "Ten BN" << setw(10) << "Goi" << setw(20) << "Thuoc" << setw(40) << "Chi Tiet Kham" << setw(5) << "Trang thai" << endl;
        cout << left << setw(10) << p.Time_w << setw(20) << p.Name_Patient << setw(10) << p.Combo << setw(20) << p.Medical << setw(40) << p.About << setw(5) << p.Status << endl;
        // cout << setfill('-') << setw(70) << endl;

        cout << "1.Thay doi trang thai." << endl;
        cout << "2.Thay chi tiet kham." << endl;
        cout << "3.Thay doi thuoc." << endl;
        cout << "4.Tro lai." << endl;
        cout << "Hay nhap yeu cau cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.Change_Status();
            cout << "Thay doi trang thai thanh cong" << endl;
            break;
        case 2:
            Change_About(p);
            break;
        case 3:
            Change_Medical(p);
            break;
        case 4:
            return;
            break;
        default:
            cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }
    } while (choice != 4);
}

void Change_About(Schedule &p)
{
    string tmp = "", line;
    cout << "Chi tiet kham: ";
    std::cin.ignore();
    std::getline(std::cin, line);

    for (int i = 0; i < line.size(); i++)
        if (line[i] == ' ')
            tmp = tmp + line[i] + '-';
        else
            tmp = tmp + line[i];
    tmp.pop_back();
    p.About = tmp;
}

void Change_Medical(Schedule &p)
{
    string line;
    int size = 0, STT;
    vector<Medical> List_Medical;
    Medical tmp;
    ifstream file("Medical.txt");
    if (!file)
    {
        cout << "Khong tin thay duoc file." << endl;
        return;
    }
    while (file >> tmp.Name >> tmp.Money)
    {
        List_Medical.push_back(tmp);
    }

    file.close();
    for (int i = 0; i < List_Medical.size(); i++)
    {
        cout << left << setw(5) << i + 1 << setw(20) << List_Medical[i].Name << setw(10) << List_Medical[i].Money << endl;
    }

    p.Medical = "";
    cout << "Nhap 0 de ket thuc." << endl;
    cout << "Nhap STT thuoc can them:";
    string tmp_string = "";
    while (cin >> STT)
    {
        if (STT == 0)
            break;
        if (STT <= List_Medical.size() && STT >= 1)
            tmp_string = tmp_string + List_Medical[STT - 1].Name + "-";
    }

    tmp_string.pop_back();
    p.Medical = tmp_string;
}
