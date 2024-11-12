
#include "Global_Function.h"
#include "Manager.h"
#include "doctor.h"
#include "Schedule.h"
#include "Medical.h"
#include "Patient.h"
#include "Service.h"
#include <string>
#include <cstdlib>

#define Sokhunggio 7
#define file_Service "Service.txt"

void Design();
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
// void update_Time_Working(Doctor &;

void Change_File_infor_Doctor(Doctor &);
void View_Schedule(const Doctor &);
void Show_Schedule(Schedule &);
void Change_File_Schedule(Schedule[], const Doctor &, string &);
void Change_About(Schedule &);
void Change_Medical(Schedule &);
void Change_Status(Schedule &);

void Patient_Workspace(Account &);
void Read_information_Patient(Patient &);
void Booking_Schedule(Patient &);
void Choice_Doctor(Schedule &, unsigned int &, string &);
bool Choice_Day_Time(Schedule &,unsigned int &, string &);
void Change_Infor_Patient(Patient &, Account &);
void Change_File_infor_Patient(Patient &);
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
        cout << " _________________________________________________________________" << endl;
        cout << "|                                                                 |" <<endl;
        cout << "|HOME                                                             |" << endl;
        cout << "|1.Dang Ky                                                        |" << endl;
        cout << "|2.Dang Nhap                                                      |" << endl;
        cout << "|3.Thoat.                                                         |" << endl;
        cout << "|_________________________________________________________________|" << endl;
        cout << "Hay nhap yeu cau cua ban: ";
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
        cout << "Tai Khoan:";
        cin >> user;
        cout << "Mat khau: ";
        cin >> pass;
        check = tmp.Register(user, pass, 4);
        if (!check)
            cout << "Tai khoan da ton tai" << endl;
    } while (!check);

    /*Tao file thong tin va lich cho benh nhan*/
    string filename = "Patient/information/" + to_string(tmp.get_Id()) + ".txt";
    ofstream file(filename);
    file.close();
    filename = "Patient/Schedule/" + to_string(tmp.get_Id()) + ".txt";
    ofstream file2(filename);
    file2.close();

    cout << "Tao tai khoan thanh cong" << endl;
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
        Manager Admin(Acc);
        cout << "1.Them Bác Sĩ" << endl;
        cout << "2.Xóa Bác Sĩ" << endl;
        cout << "3.Them Thu Ngan" << endl;
        cout << "4.Xóa Thu Ngan" << endl;
        cout << "5.Them benh nhan" << endl;
        cout << "6.Xóa benh nhan" << endl;
        cout << "7.Thoat" << endl;
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
            cout << "Xoa tai khoan thanh cong" << endl;

        else
            cout << "Xoa tai khoan that bai" << endl;
    } while (check == false);
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
            cout << "Xoa tai khoan thanh cong." << endl;
        else
            cout << "Xoa tai khoan that bai." << endl;
    } while (check == false);
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
        cout << "1.Sua thong tin ca nhan." << endl;
        cout << "2.Lich lam viec." << endl;
        cout << "3.Thoat." << endl;
        cout << "Nhap yeu cau cua ban: ";
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
    tmp.set_Time_Working(tmp_string);
    file >> tmp_string;   
    tmp.set_Exp(tmp_string);
    file.close();
}
void Change_Information_Doctor(Doctor &tmp, Account &acc)
{
    int choice = 0;
    do
    {
        cout << "1.Doi mat khau." << endl;
        cout << "2.Cap nhat ho va ten ." << endl;
        cout << "3.Cap nhat tuoi. " << endl;
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
            update_Experience(tmp);
            break;
        case 8:
            // update_Time_Working(tmp);
            break;
        case 9:
            Change_File_infor_Doctor(tmp);
            return;
        default:
            cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
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
            acc.Change_Pass();
            check = true;
        }
    } while (!check);
}
void update_Name(Person &tmp)
{
    string new_name;
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
        cout << "Gioi tinh hien tai:";
        if (tmp.get_Gender() == 'B')
            cout << "Nam" << endl;
        else if (tmp.get_Gender() == 'G')
            cout << "Nu" << endl;
        else
            cout << "Khong xac dinh." << endl;
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
        cout << "Tuoi hien tai : " << tmp.get_Age() << endl;
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
void update_Address(Person &tmp)
{
    string address;
    int choice;
    bool check = true;
    do
    {
        address  = tmp.get_Address();
        removeDashes(address);
        cout << "Dia chi hien tai : " << address << endl;
        cout << "1.Thay doi dai chi." << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap dia chi moi:";
            cin.ignore();
            getline(cin, address);
            String_processing(address);
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
void update_Phone(Person &tmp)
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
void update_Experience(Doctor &tmp)
{
    string Exp;
    int choice;
    bool check = true;
    do
    {   Exp = tmp.get_Exp();
        removeDashes(Exp);
        cout << "Kinh nghiem hien tai: " << Exp << endl;
        cout << "1.Thay doi kinh nghiem." << endl;
        cout << "2.Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Nhap kinh nghiem:";
            cin.ignore();
            getline(cin, Exp);
            String_processing(Exp);
            tmp.set_Exp(Exp);
            break;
        case 2:
            return;
        default:
            cout << "Nhap sai xin hay nhap lai." << endl;
            break;
        }

    } while (choice != 2);
}
// void update_Time_Woking(Doctor &tmp) {}
void Change_File_infor_Doctor(Doctor &tmp)
{
    string filename = "Doctor/information/" + to_string(tmp.get_ID()) + ".txt";
    ofstream file(filename);
    file << tmp.get_ID() << endl;
    file << tmp.get_Name() << endl;
    file << tmp.get_Age() << endl;
    file << tmp.get_Phone_Number() << endl;
    file << tmp.get_Address() << endl;
    file << tmp.get_Gender() << endl;
    file << tmp.get_Time_Working() << endl;
    file << tmp.get_Exp() << endl;
    file.close();
}

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
    cout << "Thoi gian hien tai la: " << getCurrentDate() << endl;
    cout << "Chon ngay xem lich lam viec: ";
    getline(cin, date_m_y);
    String_processing(date_m_y);

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
        removeDashes(List_Schedule[i].Name_Patient);
        removeDashes(List_Schedule[i].About);
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
        if (STT == 0)
        {
            cout << "Khong co lich kham." << endl;
            return;
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
            /*Luu lich lam viec moi lai vao file */
            Change_File_Schedule(List_Schedule, tmp, date_m_y);
            return;
            break;
        default:
            cout << "Nhap sai, xin hay nhap lai.";
            break;
        }
    } while (choice != 2);
}
void Change_File_Schedule(Schedule A[], const Doctor &tmp, string &date_m_y)
{
    string file_working = "Doctor/Schedule/" + to_string(tmp.get_ID()) + ".txt";
    string line;
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
                getline(file, line);
                String_processing(A[i].Name_Patient);
                String_processing(A[i].About);
                tmp_file << A[i].Time_w << " " << A[i].Id_patient << " " << A[i].Name_Patient << " " << A[i].Combo << " " << A[i].Medical << " " << A[i].About << " " << A[i].Status << endl;
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
            Change_Status(p);
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
void Change_Status(Schedule &p)
{
    p.Change_Status();
}
void Change_About(Schedule &p)
{
    string tmp = "", line;
    cout << "Chi tiet kham: ";
    cin.ignore();
    getline(cin, line);

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

void Patient_Workspace(Account &acc)
{
    int choice;
    Patient tmp;
    tmp.set_Id(acc.get_Id());
    Read_information_Patient(tmp);
    do
    {
        cout << "Giao dien dat lich hen." << endl;
        cout << "1.Dat lich kham. " << endl;
        cout << "2.Xem lai lich kham." << endl;
        cout << "3.Cap nhat thong tin." << endl;
        cout << "4.Thoat." << endl;
        cout << "Hay nhap yeu cau cua ban :";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Booking_Schedule(tmp);
            break;
        case 2:
            // View_Booking(tmp)
            break;
        case 3:
            Change_Infor_Patient(tmp, acc);
            break;
        case 4:
            return;
            break;
        default:
            cout << "Nhap sai yeu cau . Hay nhap lai." << endl;
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
    string tmp_name,day_m_y;
    string Book_Service = "", line, filename = "";
    unsigned int tmp_money, size, STT, tmp_id, id_doctor;
    Service tmp_service;
    Schedule Booking;

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

    cout << left << setw(5) << "STT" << setw(20) << "Ten Goi" << setw(10) << "Tien" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(5) << List_Service[i].id << setw(20) << List_Service[i].name << setw(10) << List_Service[i].money << "K" << endl;
    }

    cout << "Nhap STT chon goi san pham. Nhap 0 de ket thuc." << endl;
    cout << "Chon goi: ";
    do
    {
        cin >> STT;
        if (STT == 0)
            break;
        if (STT <= List_Service.size() && STT >= 1)
        {
            Book_Service = Book_Service  + to_string(STT)+ '-';
        }
    } while (STT !=0);
    if (Book_Service != "")
    {   
        Book_Service.pop_back();
        Booking.Combo = Book_Service;
        Choice_Doctor(Booking, id_doctor,day_m_y);
    }
        if (Booking.Time_w != "") {
            filename = "Patient/Schedule/" +to_string(tmp.get_ID()) +".txt";
          
            ofstream file(filename);
            file.is_open();
            file << day_m_y <<" " << Booking.Time_w <<" " <<Booking.Id_patient <<" " << Booking.Name_Patient <<" " << Booking.Combo <<" "<< Booking.Medical<<" "<<Booking.About  <<"  Y"<<endl;
        file.close();
        }
}


void Choice_Doctor(Schedule &Booking, unsigned int &id_doctor, string &day_m_y)
{

    vector<unsigned int> List_Doctor;
    vector<Doctor> List_Doctor_info;
    Schedule List_Time[Sokhunggio];
    Doctor doctor;

    int tmp_Age;
    string tmp_name, tmp_user, tmp_pass, tmp_Phone, tmp_Address, tmp_Exp,tmp_Time_Woking;
    char tmp_Gender;
    string line, filename = "";
    unsigned int size, STT, tmp_id;
    int tmp_role;

    ifstream file_acc("account.txt");
    if (!file_acc)
    {
        cout << "File not found." << endl;
        return;
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

    for (int i = 0; i < List_Doctor.size(); i++)
    {
        filename = "Doctor/information/" + to_string(List_Doctor[i]) + ".txt";
        ifstream file(filename);
        if (!file)
        {
            cout << "File not found." << endl;
            return;
        }

        file >> tmp_id;
        file >> tmp_name;
        file >> tmp_Age;
        file >> tmp_Phone;
        file >> tmp_Address;
        file >> tmp_Gender;
        file >> tmp_Time_Woking;
        file >> tmp_Exp;

        doctor.set_Name(tmp_name);
        doctor.set_Id(tmp_id);
        doctor.set_Age(tmp_Age);
        doctor.set_Phone_Number(tmp_Phone);
        doctor.set_Gender(tmp_Gender);
        doctor.set_Exp(tmp_Exp);
        doctor.set_Time_Working(tmp_Time_Woking);

        List_Doctor_info.push_back(doctor);
        file.close();
    }
   
    do
    {
         for (int i = 0; i < List_Doctor_info.size(); i++)
    {
        cout << left << setw(5) << "STT" << setw(30) << "Ten Bac Si" << setw(10) << "Tuoi" << setw(40) << "Kinh Nghiem." << endl;
        tmp_name = List_Doctor_info[i].get_Name();
        removeDashes(tmp_name);
        cout << left << setw(5) << i + 1 << setw(30) << tmp_name << setw(10) << List_Doctor_info[i].get_Age() << setw(40) << List_Doctor_info[i].get_Exp() << endl;
    }

        cout << "Nhap STT de chon bac si: ";
        cin >> STT;
        if (STT >= 1 && STT <= List_Doctor_info.size())

        {   Booking.Id_patient = List_Doctor_info[STT-1].get_ID();
            Booking.Name_Patient = List_Doctor_info[STT-1].get_Name();
            id_doctor = List_Doctor_info[STT - 1].get_ID();
            if (Choice_Day_Time(Booking, id_doctor,day_m_y))
            break;
        }
        else
        {
            cout << "STT khong hop le.!";
        }
    } while (STT < 1 || STT > List_Doctor_info.size());

}
bool Choice_Day_Time(Schedule &Booking, unsigned int &id_doctor , string &day_m_y)
{
    int choice;
    bool check = false;
    string line,tmp_time,tmp_name,tmp_Goi,tmp_medical,tmp_about,tmp_status,filename;
    unsigned int tmp_id;
    do
    {
        cout << "1.Nhap ngay kham." << endl;
        cout << "2.Chon lai bac si." << endl;
        cout << "Nhap yeu cau cua ban:";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            filename  = "Doctor/schedule/" + to_string(id_doctor) +".txt";
            ifstream file(filename);
            do
            {
                file >> line;
                if (line == add_day(getCurrentDate(),1)){}
                    break;
                for (int i = 0; i < Sokhunggio; i++)
                {
                    file >> tmp_time >> tmp_id >> tmp_name >> tmp_Goi >> tmp_medical >> tmp_about >> tmp_status;
                    if (tmp_id == 0)
                    {
                        cout << left << setw(10) << tmp_time << "Trong" << endl;
                    }
                }
            } while(line != "");
            file.close();


            do {
            cin.ignore();
            cout <<"Hom nay ngay: " << getCurrentDate() << endl;
            cout << "Nhap ngay muon Kham:";
            getline(cin, line);
            String_processing(line);
            cout << "Nhap gio muon kham:";
            cin>>tmp_time;
            String_processing(tmp_time);
            check = ((calculateDayDifference(line, getCurrentDate()) <= 15) && (calculateDayDifference(line, getCurrentDate()) > 0));
            if (!check){
                cout << "Ngay khong hop le." << endl;
                } else {
                    Booking.Time_w = tmp_time;
                    day_m_y = line;
                    return true;
                }
            } while(!check);
        }
          break;
        case 2:
            return false;
            break;
        default:
            cout << "Nhap sai yeu cau." << endl;
            break;
        }
    } while (choice != 1 || choice != 2);
}

void Change_Infor_Patient(Patient &tmp, Account &acc)
{

    int choice = 0;
    do
    {
        cout << "1.Doi mat khau." << endl;
        cout << "2.Cap nhat ho va ten ." << endl;
        cout << "3.Cap nhat tuoi. " << endl;
        cout << "4.Cap nhat gioi tinh." << endl;
        cout << "5.Cap nhat so dien thoai." << endl;
        cout << "6.Cap nhat dia chi." << endl;
        cout << "7.Thoat." << endl;
        cout << "Hay nhap yeu cau cua ban:";
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
            Change_File_infor_Patient(tmp);
            return;
        default:
            cout << "Yeu cau khong hop le. Hay nhap lai." << endl;
            break;
        }

    } while (choice != 7);
}

void Change_File_infor_Patient(Patient &tmp)
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