#include "Global_Function.h"
#include "Manager.h"
#include "doctor.h"
#include "Cashier.h"
#include "Schedule.h"
#include "Medical.h"
#include "Patient.h"
#include "Service.h"
#include <string>
#include <cstdlib>

#define Sokhunggio 7
#define file_Service "Service.txt"
void Home();
void Login();
void Register();

void Management_interface(Account &);
void Add_Doctor(Manager &);
void Add_Cashier(Manager &);
void Add_Patient(Manager &);
void Remove_Doctor(Manager &);
void Remove_Cashier(Manager &);
void Remove_Patient(Manager &);

void Doctor_Workspace(Account &);
void Read_information_doctor(Doctor &);
void Change_Information_Doctor(Doctor &, Account &);
void change_Pass(Account &);
void update_Name(Person &);
void update_Gender(Person &);
void update_Phone(Person &);
void update_Address(Person &);
void update_Age(Person &);
void update_Experience(Doctor &);
void View_Schedule(const Doctor &);
void Show_Schedule(Schedule &);
void Change_About(Schedule &);
void Change_Medical(Schedule &);
void Change_Status(Schedule &);

void Patient_Workspace(Account &);
void Read_information_Patient(Patient &);
void Booking_Schedule(Patient &);
bool Choice_Time(Schedule &, string &);
string Lay_Khung_Gio(int);
bool Choice_Doctor(Schedule &, string &);
bool Find_Doctor(Schedule &, string &, vector<unsigned int>);
void View_Booking(Patient &);
void Show_Schedule_P(Patient &, vector<string> &, vector<Schedule> &);

void Cashier_Workspace(Account &);
void Update_Schedule_Doctor(Schedule &, string, unsigned int);
void Update_Infor_Patient(Patient &, Account &);

void Update_File_infor_Patinet(Patient &);
void Update_File_Schedule_Patient(Schedule, string, Doctor);
void Update_File_Infor_Doctor(Doctor &);
void Update_File_Schedule_Doctor(Schedule[], const Doctor &, string &);
// bool isValidDate(int, int, int);

bool isEmptyPerson(const Patient &);

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
        system("cls");
        cout << "+----------------------------------------------------------------+" << endl;
        cout << "|                       DANG KY VA DANG NHAP                     |" << endl;
        cout << "+----------------------------------------------------------------+" << endl;
        cout << "|  1. Dang Ky                                                    |" << endl;
        cout << "|  2. Dang Nhap                                                  |" << endl;
        cout << "|  3. Thoat                                                      |" << endl;
        cout << "|  Hay nhap yeu cau cua ban:                                     |" << endl;
        cout << "+----------------------------------------------------------------+" << endl;

        cout << "\033[2A";
        cout << "\033[29C";
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
    } while (choice != 3);
}
void Register()
{
    Account tmp;
    string user, pass;
    bool check;

    do
    {
        system("cls");
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| Tai Khoan:                                                   |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        // cin >> user;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| Mat khau:                                                    |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        // cin >> pass;
        cout << "\033[5A\033[13C";
        cin >> user;
        cout << "\033[2B\033[12C";
        cin >> pass;
        check = tmp.Register(user, pass, 4);
        if (!check)
        {
            cout << "+--------------------------------------------------------------+" << endl;
            cout << "|          Tai khoan da ton tai! Vui long thu lai.             |" << endl;
            cout << "+--------------------------------------------------------------+" << endl;
            // sleep(3); // Dừng màn hình trong 3 giây để người dùng đọc thông báo
        }
    } while (!check);

    // Tạo file thông tin và lịch cho bệnh nhân
    string filename = "Patient/information/" + to_string(tmp.get_Id()) + ".txt";
    ofstream file(filename);
    file.close();
    filename = "Patient/Schedule/" + to_string(tmp.get_Id()) + ".txt";
    ofstream file2(filename);
    file2.close();
    system("cls");
    cout << "+--------------------------------------------------------------+" << endl;
    cout << "|                  Tao tai khoan thanh cong!                   |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;
    Sleep(3);
}

void Login()
{
    int current = 0;
    Account tmp;
    string user, pass;
    bool check;
    do
    {
        system("cls");
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| Tai Khoan:                                                   |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        // cin >> user;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| Mat khau:                                                    |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        // cin >> pass;
        cout << "\033[5A\033[13C";
        cin >> user;
        cout << "\033[2B\033[12C";
        cin >> pass;
        check = tmp.Login(user, pass);

        if (!check)
        {
            cout << "+--------------------------------------------------------------+" << endl;
            cout << "|           Tai khoan hoac mat khau khong dung!                |" << endl;
            cout << "+--------------------------------------------------------------+" << endl;
            current++;
              Sleep(2000);
            if (current == 5) return;
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
        Cashier_Workspace(tmp);
        break;
    case 4:
        Patient_Workspace(tmp);
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
        system("cls");
        Manager Admin(Acc);
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                       QUAN LY HE THONG                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Lua chon:                                                   |" << endl;
        cout << "| 1. Them Bac Si                                              |" << endl;
        cout << "| 2. Xoa Bac Si                                               |" << endl;
        cout << "| 3. Them Thu Ngan                                            |" << endl;
        cout << "| 4. Xoa Thu Ngan                                             |" << endl;
        cout << "| 5. Them Benh Nhan                                           |" << endl;
        cout << "| 6. Xoa Benh Nhan                                            |" << endl;
        cout << "| 7. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            Add_Doctor(Admin);
            break;

        case 2:
            system("cls");
            Remove_Doctor(Admin);
            break;

        case 3:
            system("cls");
            Add_Cashier(Admin);
            break;

        case 4:
            system("cls");
            Remove_Cashier(Admin);
            break;

        case 5:
            system("cls");
            Add_Patient(Admin);
            break;

        case 6:
            system("cls");
            Remove_Patient(Admin);
            break;

        case 7:
            system("cls");
            break;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Yeu cau khong hop le! Vui long nhap lai.            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 7);
}
void Add_Doctor(Manager &Admin)
{
    string user, pass;
    system("cls");

    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                     TAO TAI KHOAN BAC SI                    |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Nhap tai khoan:                                             |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Nhap mat khau:                                              |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "\033[5A\033[18C";
    cin >> user;
    cout << "\033[2B\033[17C";
    cin >> pass;

    if (Admin.Add_Doctor(user, pass))
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                Tao tai khoan thanh cong!                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
    }
    else
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                  Tao tai khoan that bai!                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
    }
}
void Remove_Doctor(Manager &Admin)
{
    string user;
    bool check;
    do
    {
        system("cls");

        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                      XOA TAI KHOAN BAC SI                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap tai khoan can xoa:                                     |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[26C";
        cin >> user;
        check = Admin.Remove_Doctor(user);
        if (check)
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                  Xoa tai khoan thanh cong!                  |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
        }
        else
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                  Xoa tai khoan that bai!                    |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
        }
    } while (!check);
}
void Add_Cashier(Manager &Admin)
{
}
void Add_Patient(Manager &Admin)
{
    string user, pass;
    system("cls");

    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                    TAO TAI KHOAN BENH NHAN                  |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Nhap tai khoan:                                             |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| Nhap mat khau:                                              |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "\033[5A\033[18C";
    cin >> user;
    cout << "\033[2B\033[17C";
    cin >> pass;
    if (Admin.Add_Cashier(user, pass))
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                  Tao tai khoan thanh cong!                  |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
    }
    else
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                   Tao tai khoan that bai!                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
    }
}
void Remove_Cashier(Manager &Admin)
{
    string user;
    bool check;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                      XOA TAI KHOAN THU NGAN                 |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap tai khoan can xoa:                                     |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[26C";
        cin >> user;
        check = Admin.Remove_Cashier(user);
        if (check)
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                  Xoa tai khoan thanh cong!                  |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
              Sleep(2000);
        }
        else
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                   Xoa tai khoan that bai!                   |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
        }
    } while (!check);
}
void Remove_Patient(Manager &Admin)
{
    string user;
    bool check;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                      XOA TAI KHOAN BENH NHAN               |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap tai khoan can xoa:                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[26C";
        cin >> user;
        check = Admin.Remove_Patient(user);
        if (check)
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                  Xoa tai khoan thanh cong!                  |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
              Sleep(2000);
        }
        else
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                   Xoa tai khoan that bai!                   |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
              Sleep(2000);
        }
    } while (!check);
}
void Doctor_Workspace(Account &acc)
{
    int choice;
    Doctor tmp;

    tmp.set_Id(acc.get_Id());
    Read_information_doctor(tmp);
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                GIAO DIEN LAM VIEC CUA BAC SI                |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| 1. Sua thong tin ca nhan                                    |" << endl;
        cout << "| 2. Xem lich lam viec                                        |" << endl;
        cout << "| 3. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap yeu cau cua ban:                                       |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[24C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            Change_Information_Doctor(tmp, acc);
            break;
        case 2:
            system("cls");
            View_Schedule(tmp);
            break;

        case 3:
            system("cls");
            return;
            break;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Yeu cau khong hop le! Vui long nhap lai.            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 3);
}
void Read_information_doctor(Doctor &tmp)
{
    string filename = "Doctor/information/" + to_string(tmp.get_ID()) + ".txt";
    ifstream file(filename);
    if (!file)
    {
        cout << "File not found." << endl;
        return;
    }
    string tmp_string;
    unsigned int tmp_int;
    char tmp_char;

    file >> tmp_int;
    file >> tmp_string;
    tmp.set_Name(tmp_string);
    file >> tmp_int;
    tmp.set_Age(tmp_int);
    file >> tmp_string;
    tmp.set_Phone_Number(tmp_string);
    file >> tmp_string;
    tmp.set_Address(tmp_string);
    file >> tmp_char;
    tmp.set_Gender(tmp_char);
    file >> tmp_string;
    tmp.set_Exp(tmp_string);
    file.close();
}
void Change_Information_Doctor(Doctor &tmp, Account &acc)
{
    int choice = 0;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                   CAP NHAT THONG TIN CA NHAN                |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| 1. Doi mat khau                                             |" << endl;
        cout << "| 2. Cap nhat ho va ten                                       |" << endl;
        cout << "| 3. Cap nhat tuoi                                            |" << endl;
        cout << "| 4. Cap nhat gioi tinh                                       |" << endl;
        cout << "| 5. Cap nhat so dien thoai                                   |" << endl;
        cout << "| 6. Cap nhat dia chi                                         |" << endl;
        cout << "| 7. Cap nhat kinh nghiem                                     |" << endl;
        cout << "| 8. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            change_Pass(acc);
            break;

        case 2:
            system("cls");
            update_Name(tmp);
            break;

        case 3:
            system("cls");
            update_Age(tmp);
            break;

        case 4:
            system("cls");
            update_Gender(tmp);
            break;

        case 5:
            system("cls");
            update_Phone(tmp);
            break;

        case 6:
            system("cls");
            update_Address(tmp);
            break;

        case 7:
            system("cls");
            update_Experience(tmp);
            break;
        case 8:
            system("cls");
            Update_File_Infor_Doctor(tmp);
            return;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|          Yeu cau khong hop le! Vui long nhap lai.           |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 9);
}
void change_Pass(Account &acc)
{
    string old_password, new_password;
    bool check = false;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                   THAY DOI MAT KHAU                         |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap mau khau cu:                                           |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap mat khau moi:                                          |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[5A\033[20C";
        cin >> old_password;
        cout << "\033[2B\033[21C";
        cin >> new_password;

        check = (old_password != acc.get_Pass());
        if (check)
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|    Mat khau dang nhap khong chinh xac. Vui long thu lai!    |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
        }
        else
        {
            acc.Set_Pass(new_password);
            acc.Change_Pass();
            check = true;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|               Thay doi mat khau thanh cong!                 |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
        }
    } while (!check);
}
void update_Name(Person &tmp)
{

    string new_name, tmp_name;
    tmp_name = tmp.get_Name();
    removeDashes(tmp_name);
    system("cls");
    cout << "+--------------------------------------------------------------+" << endl;
    cout << "|                    CAP NHAT HO VA TEN                        |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;
    cout << left << setw(20) << "| Ten hien tai: " << setw(43) << tmp_name << "|" << endl;
    cout << "+--------------------------------------------------------------+" << endl;
    cout << "| Ho va Ten:                                                   |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;
    cout << "\033[2A\033[13C";
    cin.ignore();
    getline(cin, new_name);
    String_processing(new_name);
    tmp.set_Name(new_name);
}
void update_Gender(Person &tmp)
{
    int choice = 0;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                    CAP NHAT GIOI TINH                       |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;

        cout << "| Gioi tinh hien tai: ";
        if (tmp.get_Gender() == 'B')
            cout << "Nam                                           |" << endl;
        else if (tmp.get_Gender() == 'G')
            cout << "Nu                                            |" << endl;
        else
            cout << "Khong xac dinh                          " << endl;

        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Lua chon gioi tinh moi:                                     |" << endl;
        cout << "| 1. Nam                                                      |" << endl;
        cout << "| 2. Nu                                                       |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap lua chon cua ban:                                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[26C";
        cin >> choice;

        switch (choice)
        {
        case 1:
            tmp.set_Gender('B');
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|            Gioi tinh da duoc cap nhat thanh Nam!            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        case 2:
            tmp.set_Gender('G');
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|            Gioi tinh da duoc cap nhat thanh Nu!             |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|            Lua chon khong hop le! Vui long thu lai.         |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }

        if (choice == 1 || choice == 2)
            return;

    } while (choice != 1 || choice != 2);
}

void update_Age(Person &tmp)
{
    int choice, new_age;
    bool check = true;
    do
    {
        system("cls");

        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                  CAP NHAT THONG TIN TUOI                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Tuoi hien tai: " << setw(44) << tmp.get_Age() << " |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Lua chon:                                                   |" << endl;
        cout << "| 1. Thay doi tuoi                                            |" << endl;
        cout << "| 2. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap lua chon cua ban:                                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                system("cls");

                cout << "+-------------------------------------------------------------+" << endl;
                cout << "|                      THAY DOI TUOI MOI                      |" << endl;
                cout << "+-------------------------------------------------------------+" << endl;
                cout << "| Nhap tuoi (20-100):                                         |" << endl;
                cout << "+-------------------------------------------------------------+" << endl;
                cout << "\033[2A\033[22C";
                cin >> new_age;
                if (new_age > 20 && new_age < 100)
                {
                    check = true;
                    tmp.set_Age(new_age);
                    cout << "+-------------------------------------------------------------+" << endl;
                    cout << "|                 Thay doi tuoi thanh cong!                   |" << endl;
                    cout << "+-------------------------------------------------------------+" << endl;
                }
                else
                {
                    check = false;

                    cout << "+-------------------------------------------------------------+" << endl;
                    cout << "|           Tuoi khong hop le! Vui long nhap lai.             |" << endl;
                    cout << "+-------------------------------------------------------------+" << endl;
                }
            } while (!check);
            break;

        case 2:
            return;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Lua chon khong hop le! Vui long nhap lai.           |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 2);
}
void update_Address(Person &tmp)
{
    string address;
    int choice;
    bool check = true;
    do
    {
        system("cls");

        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                  CAP NHAT THONG TIN DIA CHI                 |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        address = tmp.get_Address();
        removeDashes(address);
        cout << "| Dia chi hien tai:                                           |" << endl;
        cout << "| " << setw(59) << address.substr(0, 59) << " |" << endl;
        if (address.length() > 59)
        {
            cout << "| " << setw(59) << address.substr(59) << " |" << endl;
        }
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Lua chon:                                                   |" << endl;
        cout << "| 1. Thay doi dia chi                                         |" << endl;
        cout << "| 2. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap lua chon cua ban:                                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                   NHAP DIA CHI MOI                          |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "| Nhap dia chi:                                               |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[16C";
            cin.ignore();
            getline(cin, address);
            String_processing(address);
            tmp.set_Address(address);

            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|           Dia chi da duoc cap nhat thanh cong!              |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        case 2:
            return;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|          Lua chon khong hop le! Vui long nhap lai.          |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 2);
}
void update_Phone(Person &tmp)
{
    string new_phone;
    int choice;
    bool check = true;
    do
    {
        system("cls");

        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                 CAP NHAT SO DIEN THOAI                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| So dien thoai hien tai: " << tmp.get_Phone_Number() << setw(27) << " |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Lua chon:                                                   |" << endl;
        cout << "| 1. Thay doi so dien thoai                                   |" << endl;
        cout << "| 2. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Nhap lua chon cua ban:                                      |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[26C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "|                          NHAP SO DIEN THOAI MOI                       |" << endl;
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "| Nhap so dien thoai (10 chu so, bat dau bang '0'):                     |" << endl;
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "\033[2A\033[52C";
                cin >> new_phone;
                if (new_phone.size() == 10 && new_phone[0] == '0' && isNumeric(new_phone))
                {
                    check = true;
                    tmp.set_Phone_Number(new_phone);

                    cout << "+-------------------------------------------------------------+" << endl;
                    cout << "|        So dien thoai da duoc cap nhat thanh cong!           |" << endl;
                    cout << "+-------------------------------------------------------------+" << endl;
                }
                else
                {
                    check = false;
                    cout << "+-------------------------------------------------------------+" << endl;
                    cout << "|       So dien thoai khong hop le! Vui long nhap lai.        |" << endl;
                    cout << "+-------------------------------------------------------------+" << endl;
                }
            } while (!check);
            break;
        case 2:
            return;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Lua chon khong hop le! Vui long nhap lai.           |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 2);
}
void update_Experience(Doctor &tmp)
{
    string Exp;
    int choice;
    bool check = true;
    do
    {
        system("cls");
        Exp = tmp.get_Exp();
        removeDashes(Exp);
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                      CAP NHAT KINH NGHIEM                                      |" << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "| Kinh nghiem hien tai: " << Exp << setw(44) << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "| Lua chon:                                                                                      |" << endl;
        cout << "| 1. Thay doi kinh nghiem                                                                        |" << endl;
        cout << "| 2. Thoat                                                                                       |" << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "| Nhap lua chon cua ban:                                                                         |" << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[25C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "+------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                     NHAP KINH NGHIEM MOI                                       |" << endl;
            cout << "+------------------------------------------------------------------------------------------------+" << endl;
            cout << "+------------------------------------------------------------------------------------------------+" << endl;
            cout << "| Nhap kinh nghiem:                                                                              |" << endl;
            cout << "+------------------------------------------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[20C";
            cin.ignore();
            getline(cin, Exp);
            String_processing(Exp);
            tmp.set_Exp(Exp);
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|             Thay doi kinh nghiem thanh cong!                |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;

        case 2:
            return;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Lua chon khong hop le! Vui long thu lai.            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }

    } while (choice != 2);
}
// void update_Time_Woking(Doctor &tmp) {}
void Update_File_Infor_Doctor(Doctor &tmp)
{
    string filename = "Doctor/information/" + to_string(tmp.get_ID()) + ".txt";
    ofstream file(filename);
    file << tmp.get_ID() << endl;
    file << tmp.get_Name() << endl;
    file << tmp.get_Age() << endl;
    file << tmp.get_Phone_Number() << endl;
    file << tmp.get_Address() << endl;
    file << tmp.get_Gender() << endl;
    file << tmp.get_Exp() << endl;
    file.close();
}

void View_Schedule(const Doctor &tmp)
{
    int STT = 0, choice = 0, choice2 = 0, A[Sokhunggio];
    Schedule List_Schedule[Sokhunggio], tmp_Schedule;
    string date_m_y, line;
    string file_working = "Doctor/Schedule/" + to_string(tmp.get_ID()) + ".txt";
    ifstream file(file_working);
    if (!file)
    {
        cout << "File khong ton tai." << endl;
        return;
    }

    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                    XEM LICH LAM VIEC                        |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| 1. Lich lam viec hom nay                                    |" << endl;
        cout << "| 2. Chon ngay xem lich lam viec                              |" << endl;
        cout << "| 3. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        if (choice < 1 || choice > 3)
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|        Lua chon khong hop le. Vui long nhap lai.            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
        }
        switch (choice)
        {
        case 1:
            date_m_y = getCurrentDate();
            break;

        case 2:
            system("cls");
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "| Thoi gian hien tai la: " << getCurrentDate() << "                           |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "| Chon ngay xem lich lam viec:                                |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[31C";
            cin.ignore();
            getline(cin, date_m_y);
            String_processing(date_m_y);
            break;

        case 3:
            file.close();
            return;

        default:
            break;
        }
    } while (choice > 3 || choice < 1);

    file.clear();  // Đặt lại trạng thái của file
    file.seekg(0); // Di chuyển con trỏ về đầu file
    while (getline(file, line))
    {
        if (line == date_m_y)
            break;
    }
    if (line == "")
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                 Khong co lich lam viec!                     |" << endl;
        cout << "|           Vui long chon ngay khac de xem lich.              |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
        file.close();
        return;
    }
    for (int i = 0; i < Sokhunggio; i++)
    {
        file >> List_Schedule[i].Time_w >> List_Schedule[i].ID_person >> List_Schedule[i].Name >> List_Schedule[i].Combo >> List_Schedule[i].Medical >> List_Schedule[i].About >> List_Schedule[i].Status;
        removeDashes(List_Schedule[i].Name);
        removeDashes(List_Schedule[i].About);
    }
    file.close();

    do
    {
        system("cls");
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "|                          DANH SACH LICH KHAM                          |" << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;
        cout << "| STT  | Time    | Ten BN                   | Goi        | Trang Thai   |" << endl;
        cout << "+-----------------------------------------------------------------------+" << endl;

        for (int i = 0; i < Sokhunggio; i++)
        {
            if (List_Schedule[i].ID_person != 0)
            {
                ++STT;
                A[STT] = i;
                cout << "| " << left << setw(5) << STT
                     << "| " << setw(8) << List_Schedule[i].Time_w
                     << "| " << setw(25) << List_Schedule[i].Name
                     << "| " << setw(11) << List_Schedule[i].Combo
                     << "| " << setw(13) << Extral_Status(List_Schedule[i].Status) << "|" << endl;
            }
        }

        if (STT == 0)
        {
        cout << "|                            Lich Trong                                     |" << endl;
        cout << "+---------------------------------------------------------------------------+" << endl;
            Sleep(2000);
            return;
        }
        if (choice == 1)
        {
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "| 1. Chon benh nhan can xem chi tiet                                    |" << endl;
            cout << "| 2. Tro lai                                                            |" << endl;
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "| Hay nhap lua chon cua ban:                                            |" << endl;
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[29C";
            cin >> choice;
        }
        else
        {
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "|Nhan 1 de thoat:                                                       |" << endl;
            cout << "+-----------------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[21C";
            cin >> choice;
            if (choice != 1)
                choice = 2;
            return;
        }
        switch (choice)
        {
        case 1:
            do
            {
                cout << endl;
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "| Nhap so thu tu benh nhan can xem:                                     |" << endl;
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "\033[2A\033[36C";
                cin >> choice2;
                if (choice2 > STT || choice2 < 1)
                cout << "+-----------------------------------------------------------------------+" << endl;
                cout << "|                   STT khong ton tai!                                  |" << endl;
                cout << "+-----------------------------------------------------------------------+" << endl;
            } while (choice2 <= 0 || choice2 > STT);

            tmp_Schedule = List_Schedule[A[choice2]];
            Show_Schedule(List_Schedule[A[choice2]]);

            Update_File_Schedule_Patient(List_Schedule[A[choice2]], date_m_y, tmp);
            Update_File_Schedule_Doctor(List_Schedule, tmp, date_m_y);
            STT = 0;
            break;

        case 2:
            Update_File_Schedule_Doctor(List_Schedule, tmp, date_m_y);
            return;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                 Nhap sai! Xin hay nhap lai.                 |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }

    } while (choice != 2);
}
void Update_File_Schedule_Doctor(Schedule A[], const Doctor &tmp, string &date_m_y)
{
    string file_working = "Doctor/Schedule/" + to_string(tmp.get_ID()) + ".txt";
    string line;
    unsigned int tmp_ID;
    string tmp_name, tmp_service, tmp_time, tmp_medical, tmp_about;
    char tmp_status;
    Schedule tmp_A[Sokhunggio];
    ifstream file(file_working);
    if (!file)
    {
        cout << "Not found  file";
        return;
    }
    ofstream tmp_file("Doctor/Schedule/tmp.txt");
    while (getline(file, line))
    {
        if (line != date_m_y)
            tmp_file << line << endl;
        else
        {
            tmp_file << line << endl;
            for (int i = 0; i < Sokhunggio; i++)
            {
                file >> tmp_time >> tmp_ID >> tmp_name >> tmp_service >> tmp_medical >> tmp_about >> tmp_status;
                tmp_A[i] = Schedule(tmp_time, tmp_ID, tmp_name, tmp_service, tmp_medical, tmp_about, tmp_status);
            }
            for (int i = 1; i < Sokhunggio; i++)
                if (tmp_A[i].ID_person != A[i].ID_person)
                {
                    A[i] = tmp_A[i];
                }
            for (int i = 0; i < Sokhunggio; i++)
            {
                String_processing(A[i].Name);
                String_processing(A[i].About);
                tmp_file << A[i].Time_w << " " << A[i].ID_person << " " << A[i].Name << " " << A[i].Combo << " " << A[i].Medical << " " << A[i].About << " " << A[i].Status << endl;
            }
        }
    }
    file.close();
    tmp_file.close();

    /*Copy file tmp sang file cu*/
    ifstream tmp_file_2("Doctor/Schedule/tmp.txt");
    if (!tmp_file_2)
    {
        cout << "Not found file." << endl;
        return;
    }

    ofstream file_2(file_working);
    file_2 << tmp_file_2.rdbuf();
    file_2.close();
    tmp_file_2.close();
}

void Show_Schedule(Schedule &p)
{
    int choice;
    do
    {
        system("cls");
        cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "|                                                                       THONG TIN CHI TIET                                                                 |" << endl;
        cout << "+----------+------------------------------+-------------------------+-------------------------------+---------------------------------------+--------------+" << endl;
        cout << "|   Time   | Ten BN                       | Goi                     | Thuoc                         | Chi Tiet Kham                         | Trang Thai   |" << endl;
        cout << "+----------+------------------------------+-------------------------+-------------------------------+---------------------------------------+--------------+" << endl;
        cout << "|   " << left << setw(7) << p.Time_w
             << "| " << setw(29) << p.Name
             << "| " << setw(24) << p.Combo
             << "| " << setw(30) << p.Medical
             << "| " << setw(38) << p.About
             << "| " << setw(11) << Extral_Status(p.Status) << "  |" << endl;
        cout << "+----------+------------------------------+-------------------------+-------------------------------+---------------------------------------+--------------+" << endl;

        cout << "| 1. Thay doi trang thai                                                                                                                                   |" << endl;
        cout << "| 2. Thay chi tiet kham                                                                                                                                    |" << endl;
        cout << "| 3. Thay doi thuoc                                                                                                                                        |" << endl;
        cout << "| 4. Tro lai                                                                                                                                               |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                                                                                                                |" << endl;
        cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Change_Status(p);
            cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                                                   Thay doi trang thai thanh cong!                                                        |" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
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
            cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
            cout << "|                                                             Yeu cau khong hop le! Vui long nhap lai.                                                     |" << endl;
            cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 4);
}
void Change_Status(Schedule &p)
{
    p.Change_Status();
}
void Change_About(Schedule &p)
{
    string line;
    cout << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "| Chi tiet kham:                                                                                                                                           |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "\033[2A\033[17C";
    cin.ignore();
    getline(cin, line);
    String_processing(line);
    p.About = line;
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                        Chi tiet kham da duoc cap nhat thanh cong!                                                        |" << endl;
    cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

void Change_Medical(Schedule &p)
{
    string line;
    int STT;
    vector<Medical> List_Medical;
    Medical tmp;

    // Mở file Medical.txt
    ifstream file("Medical.txt");
    if (!file)
    {
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|               Khong tim thay file Medical.txt!              |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        Sleep(2000);
        return;
    }

    // Đọc dữ liệu thuốc từ file vào vector
    while (file >> tmp.Name >> tmp.Money)
    {
        List_Medical.push_back(tmp);
    }
    file.close();
    // cout << endl;
    system("cls");
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                       DANH SACH THUOC                       |" << endl;
    cout << "+-----+--------------------+----------------------------------+" << endl;
    cout << "| STT | Ten Thuoc          | Gia                              |" << endl;
    cout << "+-----+--------------------+----------------------------------+" << endl;
    for (int i = 0; i < List_Medical.size(); i++)
    {
        cout << "| " << left << setw(4) << i + 1
             << "| " << setw(19) << List_Medical[i].Name
             << "| " << setw(10) << List_Medical[i].Money << "                       |" << endl;
    }
    cout << "+-----+--------------------+----------------------------------+" << endl;
    p.Medical = "";
    cout << "| Nhap STT thuoc can them va nhap 0 de ket thuc:              |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "\033[2A\033[49C";
    string tmp_string = "";
    while (cin >> STT)
    {
        if (STT == 0)
            break;
        if (STT >= 1 && STT <= List_Medical.size())
        {
            tmp_string += List_Medical[STT - 1].Name + "-";
        }
        else
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|             STT khong hop le! Vui long nhap lai.            |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
        }
    }
    if (!tmp_string.empty())
        tmp_string.pop_back();

    p.Medical = tmp_string;
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "|                 Cap nhat danh sach thuoc thanh cong!        |" << endl;
    cout << "+-------------------------------------------------------------+" << endl;
}

void Update_File_Schedule_Patient(Schedule p, string Date, Doctor doctor)
{
    string filename, tmp_date, tmp_time, tmp_service, tmp_medical, tmp_about, tmp_name;
    char tmp_status;
    Schedule tmp_Schedule;
    int choice;
    unsigned int tmp_ID, ID_Patient;
    vector<Schedule> List_Schedule;
    vector<string> List_Date;
    ID_Patient = p.ID_person;

    filename = "Patient/Schedule/" + to_string(ID_Patient) + ".txt";
    ifstream file(filename);

    while (file >> tmp_date >> tmp_time >> tmp_ID >> tmp_name >> tmp_service >> tmp_medical >> tmp_about >> tmp_status)
    {
        if (tmp_date != "")
        {
            // removeDashes(tmp_name);
            List_Date.push_back(tmp_date);
            tmp_Schedule = Schedule(tmp_time, tmp_ID, tmp_name, tmp_service, tmp_medical, tmp_about, tmp_status);
            List_Schedule.push_back(tmp_Schedule);
        }
    }
    file.close();

    p.Name = doctor.get_Name();
    p.ID_person = doctor.get_ID();

    for (int i = 0; i < List_Schedule.size(); i++)
        if (List_Date[i] == Date && List_Schedule[i].Time_w == p.Time_w && List_Schedule[i].ID_person == p.ID_person)
        {
            List_Schedule[i] = p;
            break;
        }

    ofstream file2(filename);
    for (int i = 0; i < List_Schedule.size(); i++)
    {
        file2 << List_Date[i] << " " << List_Schedule[i].Time_w << " "
              << List_Schedule[i].ID_person << " " << List_Schedule[i].Name << " "
              << List_Schedule[i].Combo << " " << List_Schedule[i].Medical << " "
              << List_Schedule[i].About << " " << List_Schedule[i].Status << endl;
    }
    file2.close();
}

// void Cashier_Workspace(Account &acc){
//     int choice;
//     Cashier tmp;
//     tmp.set_Id(acc.get_Id());
//     Read_information_Cashier(Tmp);
//     do {
//         cout << "+--------------------------------------------------------------+" << endl;
//         cout << "|                    GIAO DIEN LAM VIEC                        |" << endl;
//         cout << "+--------------------------------------------------------------+" << endl;
//         cout << "|   1. Xuat hoa don                                            |" << endl;
//         cout << "|   2. Thong ke trong ngay                                     |" << endl;
//         cout << "|   3. Cap nhat thong tin                                      |" << endl;
//         cout << "|   4. Thoat                                                   |" << endl;
//         cout << "|   Hay nhap yeu cau cua ban:                                  |" << endl;
//         cout << "+--------------------------------------------------------------+" << endl;
//         cout << "\033[2A";
//         cout << "\033[30C";
//         cin >> choice;
//          switch (choice)
//          {
//          case 1:
//             Export_Bill();
//             break;
//          case 2:
//             Total_Day();
//             break;
//          case 3:
//             Update_Infor_Cashier(tmp);
//             break;
//         case 4:
//         return;
//         default:
//         cout << "+-------------------------------------------------------------+" << endl;
//         cout << "|               Nhap sai yeu cau! Hay nhap lai.               |" << endl;
//         cout << "+-------------------------------------------------------------+" << endl;
//         break;
//          }

//     } while(choice != 4);
// }
// void Export_Bill(){
//     // unsigned int ID;
//     // int Age;
//     // string Name,NumberPhone,Address,str_Gender;
//     // char Gender;
//     // Schedule tmp_Schedule;
//     // string filename,day,filename2;
//     // cout << "+-------------------------------------------------------------+" << endl;
//     // cout << "| Nhap ma benh nhan muon xuat hoa don:                        |" << endl;
//     // cout << "+-------------------------------------------------------------+" << endl;
//     // cout << "\033[2A\033[28C";
//     // cin >> ID;
//     // filename ="Patient/Schedule/"+to_string(ID) +".txt";
//     // ifstream file(filename);
//     // while(file >> day){
//     //     if (day != getCurrentDate()) {
//     //         file >> tmp_Schedule.Time_w >> tmp_Schedule.ID_person >> tmp_Schedule.Name >> tmp_Schedule.Medical >> tmp_Schedule.About >> tmp_Schedule.Status;
//     //         break;
//     //     }
//     // getline(file,day);
//     // }
//     // file.close();
//     // removeDashes(tmp_Schedule.Name);
//     // removeDashes(tmp_Schedule.About);
//     // filename = "Patient/Information/"+to_string(ID) +".txt";
//     // ifstream file(filename);
//     // file >> ID >> Name >> Age >> NumberPhone >> Address >> Gender;
//     // file.close();
//     // if (Gender == 'G') str_Gender ="Nam" else str_Gender = "Nu";
//     // filename2 = "Bill/"+getCurrentDate() +"-"+ Name +".txt";
//     // removeDashes(Name);
//     // ofstream file2(filename2);
//     //     cout << "+--------------------------------------------------------------+" << endl;
//     //     cout << "|                         HOA DON                              |" << endl;
//     //     cout << "+--------------------------------------------------------------+" << endl;
//     //     cout << "|   Benh nhan: "<<left<<setw(20) <<Name    <<"                 |" << endl;
//     //     cout << "|   Gioi tinh: "<<left<<setw(10)<<str_Gender <<"Tuoi :" <<setw(5) << Age  <<"    |" << endl;
//     //     cout << "|   Bac si   : "<<left<<setw(20)<< tmp_Schedule.Name <<"                  |" << endl;
//     //     cout << "|--------------------------------------------------------------|" << endl;
//     //     cout << "|   Goi Dich Vu        |    So Luong    |      Thanh Tien      |" << endl;
//     //     cout << "+--------------------------------------------------------------+" << endl;
//     //     cout << "|                                       |Tong: "<< Total_Money "|" << endl;
//     //     file2 << "+--------------------------------------------------------------+" << endl;
// }
// void Total_Day(){
// }
// void Total_Month(){

// }
// void Update_Infor_Cashier(Cashier &tmp, Account &acc)
// {
//     int choice = 0;
//     do
//     {
//         system("cls");
//         cout << "+-------------------------------------------------------------+" << endl;
//         cout << "|                   Cap Nhat Thong Tin                        |" << endl;
//         cout << "+-------------------------------------------------------------+" << endl;
//         cout << "| 1. Doi mat khau                                             |" << endl;
//         cout << "| 2. Cap nhat ho va ten                                       |" << endl;
//         cout << "| 3. Cap nhat tuoi                                            |" << endl;
//         cout << "| 4. Cap nhat gioi tinh                                       |" << endl;
//         cout << "| 5. Cap nhat so dien thoai                                   |" << endl;
//         cout << "| 6. Cap nhat dia chi                                         |" << endl;
//         cout << "| 7. Thoat                                                    |" << endl;
//         cout << "+-------------------------------------------------------------+" << endl;
//         cout << "| Hay nhap yeu cau cua ban:                                   |" << endl;
//         cout << "+-------------------------------------------------------------+" << endl;
//         cout << "\033[2A\033[28C";
//         cin >> choice;
//         switch (choice)
//         {
//         case 1:
//             change_Pass(acc);
//             break;
//         case 2:
//             update_Name(tmp);
//             break;
//         case 3:
//             update_Age(tmp);
//             break;
//         case 4:
//             update_Gender(tmp);
//             break;
//         case 5:
//             update_Phone(tmp);
//             break;
//         case 6:
//             update_Address(tmp);
//             break;
//         case 7:
//             Update_File_infor_Cashier(tmp);
//             return;
//         default:
//             cout << "+-------------------------------------------------------------+" << endl;
//             cout << "|           Yeu cau khong hop le! Vui long nhap lai.          |" << endl;
//             cout << "+-------------------------------------------------------------+" << endl;
//             break;
//         }

//     } while (choice != 7);
// }
// void Update_File_infor_Cashier(Cashier &){
//     string filename = "Cashier/information/" + to_string(tmp.get_ID()) + ".txt";
//     ofstream file(filename);
//     file << tmp.get_ID() << endl;
//     file << tmp.get_Name() << endl;
//     file << tmp.get_Age() << endl;
//     file << tmp.get_Phone_Number() << endl;
//     file << tmp.get_Address() << endl;
//     file << tmp.get_Gender() << endl;
//     file.close();
// }

void Patient_Workspace(Account &acc)
{
    int choice;
    Patient tmp;
    tmp.set_Id(acc.get_Id());
    Read_information_Patient(tmp);
    do
    {
        system("cls");
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "|                    GIAO DIEN DAT LICH HEN                    |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "|   1. Dat lich kham                                           |" << endl;
        cout << "|   2. Xem lai lich kham                                       |" << endl;
        cout << "|   3. Cap nhat thong tin                                      |" << endl;
        cout << "|   4. Thoat                                                   |" << endl;
        cout << "|   Hay nhap yeu cau cua ban:                                  |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;

        cout << "\033[2A";
        cout << "\033[30C";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (isEmptyPerson(tmp))
            {
                cout << "\033[2C";
                cout << "+-------------------------------------------------------------+" << endl;
                cout << "|             Vui long nhap day du thong tin!                 |" << endl;
                cout << "+-------------------------------------------------------------+" << endl;
                // Sleep(1500);
                break;
            }
            Booking_Schedule(tmp);
            break;
        case 2:
            View_Booking(tmp);
            break;
        case 3:
            Update_Infor_Patient(tmp, acc);
            break;
        case 4:
            return;
            break;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|               Nhap sai yeu cau! Hay nhap lai.               |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 4);
}

void Read_information_Patient(Patient &tmp)
{
    string filename = "Patient/information/" + to_string(tmp.get_ID()) + ".txt";
    ifstream file(filename);
    if (!file)
    {
        cout << "File not found." << endl;
        return;
    }
    string tmp_string;
    unsigned int tmp_int;
    char tmp_char;

    file >> tmp_int;
    file >> tmp_string;
    tmp.set_Name(tmp_string);
    file >> tmp_int;
    tmp.set_Age(tmp_int);
    file >> tmp_string;
    tmp.set_Phone_Number(tmp_string);
    file >> tmp_string;
    tmp.set_Address(tmp_string);
    file >> tmp_char;
    tmp.set_Gender(tmp_char);
    file >> tmp_string;
    file.close();
}

void Booking_Schedule(Patient &tmp)
{
    vector<Service> List_Service;
    string tmp_name, Date;
    string Book_Service = "", line, filename = "", convert_money;
    unsigned int tmp_money, size, STT, tmp_id, id_doctor;
    Service tmp_service;
    Schedule Booking, Booking_for_Doctor;
    Doctor doctor;
    ifstream file(file_Service);
    if (!file)
    {
        cout << "Khong tin thay duoc file." << endl;
        return;
    }

    file >> size;
    for (int i = 0; i < size; i++)
    {
        file >> tmp_id >> tmp_name >> tmp_money;
        removeDashes(tmp_name);
        tmp_service = Service(tmp_id, tmp_name, tmp_money);
        List_Service.push_back(tmp_service);
    }
    file.close();
    system("cls");

    cout << "+--------------------------------------------------------------------------------+" << endl;
    cout << left << setw(10) << "| STT" << setw(20) << "Ten Goi" << setw(10) << "Don Gia" << setw(41) << " " << setw(1) << "|" << endl;
    cout << "+--------------------------------------------------------------------------------+" << endl;

    for (int i = 0; i < size; i++)
    {
        convert_money = to_string(List_Service[i].money) + "K";
        cout << left << setw(3) << "|" << setw(7) << List_Service[i].id << setw(20) << List_Service[i].name << setw(10) << convert_money << setw(41) << " " << setw(1) << "|" << endl;
    }

    cout << "+--------------------------------------------------------------------------------+" << endl;
    cout << "| Nhap STT chon goi san pham. Co the chon nhieu goi. Nhap 0 de ket thuc chon goi.|" << endl;
    cout << "| Chon goi:                                                                      |" << endl;
    cout << "+--------------------------------------------------------------------------------+" << endl;
    cout << "\033[2A\033[12C";
    do
    {
        cin >> STT;
        if (STT == 0)
            break;
        if (STT <= List_Service.size() && STT >= 1)
        {
            Book_Service = Book_Service + to_string(STT) + '-';
        }
    } while (STT != 0);
    if (Book_Service != "")
    {
        Book_Service.pop_back();
        Booking.Combo = Book_Service;
        if (Choice_Time(Booking, Date) == true)
        {
            Booking_for_Doctor = Booking;
            Booking_for_Doctor.Name = tmp.get_Name();
            Booking_for_Doctor.ID_person = tmp.get_ID();
            Update_Schedule_Doctor(Booking_for_Doctor, Date, Booking.ID_person);

            filename = "Patient/Schedule/" + to_string(tmp.get_ID()) + ".txt";
            ofstream file(filename, ios::app);
            file << Date << " " << Booking.Time_w << " " << Booking.ID_person << " " << Booking.Name << " " << Booking.Combo << " " << Booking.Medical << " " << Booking.About << " " << Booking.Status << endl;
            file.close();
        }
    }
}
bool Choice_Time(Schedule &Booking, string &Date)
{
    int choice;
    int STT, calculateDay;
    bool check = false;
    string tmp_day, tmp_time;
    do
    {
        system("cls");
        cout << "+----------------------------------------------------------------+" << endl;
        cout << "| Da chon goi: " << Booking.Combo << "                                                 |" << endl;
        cout << "| 1.Nhap ngay kham                                               |" << endl;
        cout << "| 2.Tro lai                                                      |" << endl;
        cout << "| Nhap yeu cau cua ban:                                          |" << endl;
        cout << "+----------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[24C";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            do
            {
                system("cls");
                cin.ignore();
                cout << "+--------------------------------------------------------------------------------------+" << endl;
                cout << "| Vui long dat truoc " << add_day(getCurrentDate(), 15) << "                                                        |" << endl;
                cout << "| Nhap ngay thang nam muon kham:                                                       |" << endl;
                cout << "+--------------------------------------------------------------------------------------+" << endl;
                cout << "\033[2A\033[33C";
                getline(cin, tmp_day);
                String_processing(tmp_day);
                cout << endl;
                cout << "| 1. 7-8      2. 8-9      3. 9-10        4.10-11      5. 2-3        6. 3-4      7.4-5  |" << endl;
                cout << "| Nhap STT khung gio muon kham:                                                        |" << endl;
                cout << "+--------------------------------------------------------------------------------------+" << endl;
                cout << "\033[2A\033[32C";
                cin >> STT;
                tmp_time = Lay_Khung_Gio(STT);
                calculateDay = calculateDayDifference(tmp_day, getCurrentDate());
                check = ((calculateDay <= 15) && (calculateDay > 0));
                if (check == false || tmp_time == "Error")
                {
                    cout << "+-------------------------------------------------------------+" << endl;
                    cout << "|             Ngay hoac khung gio khong hop le!               |" << endl;
                    cout << "+-------------------------------------------------------------+" << endl;
                    Sleep(2000);
                    check = false;
                }
                if (check)
                {
                    Date = tmp_day;
                    Booking.Time_w = tmp_time;
                    if (Choice_Doctor(Booking, Date))
                        return true;
                    else
                    {
                        break;
                    }
                }
            } while (!check);
        }
        break;
        case 2:
            return false;
            break;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                     Nhap sai yeu cau!                       |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }
    } while (choice != 2);
}
string Lay_Khung_Gio(int STT)
{

    switch (STT)
    {
    case 1:
        return "7-8";
        break;
    case 2:
        return "8-9";
        break;
    case 3:
        return "9-10";
        break;
    case 4:
        return "10-11";
        break;
    case 5:
        return "2-3";
        break;
    case 6:
        return "3-4";
        break;
    case 7:
        return "4-5";
        break;
    default:
        return "Error";
        break;
    }
}

bool Choice_Doctor(Schedule &Booking, string &Date)
{

    vector<unsigned int> List_Doctor;
    Schedule List_Time[Sokhunggio];
    string line, tmp_user, tmp_pass, filename = "";
    unsigned int size, STT, tmp_id;
    int tmp_role;

    ifstream file_acc("account.txt");
    if (!file_acc)
    {
        cout << "File not found." << endl;
        return false;
    }

    file_acc >> size;
    for (int i = 0; i < size; i++)
    {
        file_acc >> tmp_id >> tmp_user >> tmp_pass >> tmp_role;
        if (tmp_role == 2)
        {
            List_Doctor.push_back(tmp_id);
        }
    }

    file_acc.close();
    if (!Find_Doctor(Booking, Date, List_Doctor))
    {
        return false;
    }
    return true;
}

bool Find_Doctor(Schedule &Booking, string &Date, vector<unsigned int> List_Doctor)
{
    Doctor doctor;
    string filename, line;
    string tmp_name, tmp_user, tmp_pass, tmp_Phone, tmp_Address, tmp_Exp, tmp_Time_Woking;
    string tmp_time, tmp_Service, tmp_medical, tmp_about, tmp_status;
    vector<unsigned int> DS_BS_Lich_Trong;
    vector<Doctor> List_Doctor_info;
    unsigned int tmp_id;
    int STT;
    int tmp_Age;
    char tmp_Gender;

    for (int i = 0; i < List_Doctor.size(); i++)
    {
        filename = "Doctor/schedule/" + to_string(List_Doctor[i]) + ".txt";
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return false;
        }

        while (getline(file, line))
        {
            if (line == Date)
            {
                for (int j = 0; j < Sokhunggio; j++)
                {
                    file >> tmp_time >> tmp_id >> tmp_name >> tmp_Service >> tmp_medical >> tmp_about >> tmp_status;
                    if (tmp_time == Booking.Time_w && tmp_id == 0)
                    {
                        DS_BS_Lich_Trong.push_back(List_Doctor[i]);
                        break;
                    }
                }
                break;
            }
        }
    }

    if (DS_BS_Lich_Trong.size() == 0)
    {
        cout << "Khong co BS trong ngay: " << Date << " Gio:" << Booking.Time_w << endl;
        return false;
    }

    for (int i = 0; i < DS_BS_Lich_Trong.size(); i++)
    {
        filename = "Doctor/information/" + to_string(DS_BS_Lich_Trong[i]) + ".txt";
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return false;
        }

        file >> tmp_id;
        file >> tmp_name;
        file >> tmp_Age;
        file >> tmp_Phone;
        file >> tmp_Address;
        file >> tmp_Gender;
        file >> tmp_Exp;
        doctor.set_Name(tmp_name);
        doctor.set_Id(tmp_id);
        doctor.set_Age(tmp_Age);
        doctor.set_Phone_Number(tmp_Phone);
        doctor.set_Gender(tmp_Gender);
        doctor.set_Exp(tmp_Exp);
        List_Doctor_info.push_back(doctor);
        file.close();
    }

    do
    {
        system("cls");
        cout << "+--------------------------------------------------------------------------------------+" << endl;
        cout << "| " << left << setw(5) << "STT"
             << setw(35) << "Ten Bac Si"
             << setw(8) << "Tuoi"
             << setw(30) << "Kinh Nghiem"
             << "       |" << endl;
        cout << "+--------------------------------------------------------------------------------------+" << endl;

        for (int i = 0; i < List_Doctor_info.size(); i++)
        {
            tmp_name = List_Doctor_info[i].get_Name();
            removeDashes(tmp_name); // Xử lý tên bác sĩ nếu cần
            tmp_Exp = List_Doctor_info[i].get_Exp();
            removeDashes(tmp_Exp);
            cout << "| " << left
                 << setw(5) << i + 1
                 << setw(35) << tmp_name
                 << setw(8) << List_Doctor_info[i].get_Age()
                 << setw(30) << tmp_Exp
                 << "       |" << endl;
        }

        cout << "+--------------------------------------------------------------------------------------+" << endl;
        cout << "| Nhap STT de chon bac si:                                                             |" << endl;
        cout << "+--------------------------------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[27C";
        cin >> STT;
        if (STT >= 1 && STT <= List_Doctor_info.size())

        {
            Booking.Name = List_Doctor_info[STT - 1].get_Name();
            Booking.ID_person = List_Doctor_info[STT - 1].get_ID();
            cout << "+----------------------------------------------------------------------------------+" << endl;
            cout << "|                              Dat lich thanh cong!                                |" << endl;
            cout << "+----------------------------------------------------------------------------------+" << endl;
            Sleep(2000);
            return true;
        }
        else
        {
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                     STT khong hop le!                       |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
        }
    } while (STT < 1 || STT > List_Doctor_info.size());
}

void View_Booking(Patient &tmp)
{
    string filename, tmp_date, tmp_time, tmp_service, tmp_medical, tmp_about, tmp_name;
    char tmp_status;
    Schedule tmp_Schedule;
    int choice;
    unsigned int tmp_ID;
    vector<Schedule> List_Schedule;
    vector<string> List_Date;

    filename = "Patient/Schedule/" + to_string(tmp.get_ID()) + ".txt";
    ifstream file(filename);
    if (!file)
    {
        cout << "Khong tim thay file." << endl;
        return;
    }
    while (file >> tmp_date >> tmp_time >> tmp_ID >> tmp_name >> tmp_service >> tmp_medical >> tmp_about >> tmp_status)
    {
        if (tmp_date != "")
        {
            List_Date.push_back(tmp_date);
            tmp_Schedule = Schedule(tmp_time, tmp_ID, tmp_name, tmp_service, tmp_medical, tmp_about, tmp_status);
            List_Schedule.push_back(tmp_Schedule);
        }
    }
    if (List_Schedule.size() == 0)
    {
        cout << "Chua co lich hen." << endl;
        return;
    }
    do
    {
        system("cls");
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "| " << left << setw(10) << "STT"
             << setw(15) << "Ngay"
             << setw(10) << "Gio"
             << setw(30) << "Ten Bac Si"
             << setw(10) << "Trang Thai" << "                    |" << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;

        for (int i = 0; i < List_Schedule.size(); i++)
        {
            tmp_name = List_Schedule[i].Name;
            removeDashes(tmp_name);
            cout << "| " << left << setw(10) << i + 1
                 << setw(15) << List_Date[i]
                 << setw(10) << List_Schedule[i].Time_w
                 << setw(30) << tmp_name
                 << setw(10) << Extral_Status(List_Schedule[i].Status)
                 << "                    |" << endl;
        }
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "| 1. Xem chi tiet.                                                                               |" << endl;
        cout << "| 2. Tro lai.                                                                                    |" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                                                      |" << endl;
        cout << "+------------------------------------------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Show_Schedule_P(tmp, List_Date, List_Schedule);
            break;
        case 2:
            return;
            break;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|                  Nhap sai! Hay nhap lai.                    |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
            break;
        }

    } while (choice != 2);
}

void Show_Schedule_P(Patient &tmp, vector<string> &List_Date, vector<Schedule> &List_Schedule)
{
    int choice, STT;
    string tmp_name;
    Schedule tmp_Schedule;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| " << left << setw(10) << "STT"
             << setw(15) << "Ngay"
             << setw(10) << "Gio"
             << setw(20) << "Ten Bac Si"
             << setw(10) << "Goi"
             << setw(20) << "Thuoc"
             << setw(30) << "Chu Thich"
             << setw(10) << "Trang Thai" << " |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
        for (int i = 0; i < List_Schedule.size(); i++)
        {
            tmp_name = List_Schedule[i].Name;
            removeDashes(tmp_name);
            cout << "| " << left << setw(10) << i + 1
                 << setw(15) << List_Date[i]
                 << setw(10) << List_Schedule[i].Time_w
                 << setw(20) << tmp_name
                 << setw(10) << List_Schedule[i].Combo
                 << setw(20) << List_Schedule[i].Medical
                 << setw(30) << List_Schedule[i].About
                 << setw(10) << Extral_Status(List_Schedule[i].Status) << " |" << endl;
        }
        cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "| 1. Huy lich hen.                                                                                                              |" << endl;
        cout << "| 2. Tro lai.                                                                                                                   |" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                                                                                     |" << endl;
        cout << "+-------------------------------------------------------------------------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            // system("cls");
            int STT;
            cout << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "| Nhap STT cua lich hen muon huy:                             |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "\033[2A\033[34C";
            cin >> STT;

            if (calculateDayDifference(List_Date[STT - 1], getCurrentDate()) <= 1)
            {
                cout << "+-------------------------------------------------------------+" << endl;
                cout << "|         Khong the huy lich hen truoc 1 ngay!                |" << endl;
                cout << "+-------------------------------------------------------------+" << endl;
                Sleep(2000);
            }
            else
            {
                tmp_Schedule.Time_w = List_Schedule[STT - 1].Time_w;
                Update_Schedule_Doctor(tmp_Schedule, List_Date[STT - 1], List_Schedule[STT - 1].ID_person);
                List_Date.erase(List_Date.begin() + (STT - 1));
                List_Schedule.erase(List_Schedule.begin() + (STT - 1));

                string filename = "Patient/Schedule/" + to_string(tmp.get_ID()) + ".txt";
                ofstream file(filename);
                for (int i = 0; i < List_Date.size(); i++)
                {
                    String_processing(List_Schedule[i].Name);
                    file << List_Date[i] << " " << List_Schedule[i].Time_w << " "
                         << List_Schedule[i].ID_person << " " << List_Schedule[i].Name << " "
                         << List_Schedule[i].Combo << " " << List_Schedule[i].Medical << " "
                         << List_Schedule[i].About << " " << List_Schedule[i].Status << endl;
                }
                file.close();

                cout << "+-------------------------------------------------------------+" << endl;
                cout << "|                 Huy lich hen thanh cong!                    |" << endl;
                cout << "+-------------------------------------------------------------+" << endl;
                Sleep(2000);
            }
            break;
        }
        case 2:
            break;

        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|         Lua chon khong hop le! Vui long nhap lai.           |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            Sleep(2000);
            break;
        }
    } while (choice != 2);
}
void Update_Infor_Patient(Patient &tmp, Account &acc)
{

    int choice = 0;
    do
    {
        system("cls");
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "|                   Cap Nhat Thong Tin                        |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| 1. Doi mat khau                                             |" << endl;
        cout << "| 2. Cap nhat ho va ten                                       |" << endl;
        cout << "| 3. Cap nhat tuoi                                            |" << endl;
        cout << "| 4. Cap nhat gioi tinh                                       |" << endl;
        cout << "| 5. Cap nhat so dien thoai                                   |" << endl;
        cout << "| 6. Cap nhat dia chi                                         |" << endl;
        cout << "| 7. Thoat                                                    |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "| Hay nhap yeu cau cua ban:                                   |" << endl;
        cout << "+-------------------------------------------------------------+" << endl;
        cout << "\033[2A\033[28C";
        cin >> choice;
        switch (choice)
        {
        case 1:
            change_Pass(acc);
            break;
        case 2:
            update_Name(tmp);
            break;
        case 3:
            update_Age(tmp);
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
            Update_File_infor_Patinet(tmp);
            return;
        default:
            cout << "+-------------------------------------------------------------+" << endl;
            cout << "|           Yeu cau khong hop le! Vui long nhap lai.          |" << endl;
            cout << "+-------------------------------------------------------------+" << endl;
            break;
        }

    } while (choice != 7);
}

void Update_File_infor_Patinet(Patient &tmp)
{
    string filename = "Patient/information/" + to_string(tmp.get_ID()) + ".txt";
    ofstream file(filename);
    file << tmp.get_ID() << endl;
    file << tmp.get_Name() << endl;
    file << tmp.get_Age() << endl;
    file << tmp.get_Phone_Number() << endl;
    file << tmp.get_Address() << endl;
    file << tmp.get_Gender() << endl;
    file.close();
}

bool isEmptyPerson(const Patient &p)
{
    if (
        p.get_Name().empty() &&
        p.get_Phone_Number().empty() &&
        p.get_Address().empty())
    {
        return true;
    }
    return false; // Đối tượng có thông tin
}

void Update_Schedule_Doctor(Schedule &schedule, string Date, unsigned int ID_Doctor)
{
    Schedule List_Schedule[Sokhunggio];
    string line;
    string filename = "Doctor/Schedule/" + to_string(ID_Doctor) + ".txt";
    ifstream file(filename);
    Doctor doctor;
    doctor.set_Id(ID_Doctor);
    while (getline(file, line))
    {
        if (line == Date)
        {
            for (int i = 0; i < Sokhunggio; i++)
            {
                file >> List_Schedule[i].Time_w >> List_Schedule[i].ID_person >> List_Schedule[i].Name >> List_Schedule[i].Combo >> List_Schedule[i].Medical >> List_Schedule[i].About >> List_Schedule[i].Status;
                removeDashes(List_Schedule[i].Name);
                removeDashes(List_Schedule[i].About);
            }
            break;
        }
    }
    file.close();
    removeDashes(schedule.Name);
    for (int i = 0; i < Sokhunggio; i++)
        if (List_Schedule[i].Time_w == schedule.Time_w)
        {
            List_Schedule[i] = schedule;
            break;
        }
    Update_File_Schedule_Doctor(List_Schedule, doctor, Date);
}
