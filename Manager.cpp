#include "Manager.h"
#include "Global_Function.h"

void Add_File_Schedule_D(unsigned int );
void Add_File_Information_D(unsigned int );
void Delete_file(const string &);

void Add_File_Schedule_D(unsigned int id)
{
    string filename = "Doctor/Schedule/" + to_string(id) + ".txt";
    ofstream file(filename);
    for (int i = 15; i >= 0; i--)
    {   
        file << add_day(getCurrentDate(),i) << endl;
        file << "7-8 0 0 0 0 0 N" << endl;
        file << "8-9 0 0 0 0 0 N" << endl;
        file << "9-10 0 0 0 0 0 N" << endl;
        file << "10-11 0 0 0 0 0 N" <<endl;
        file << "2-3 0 0 0 0 0 N" << endl;
        file << "3-4 0 0 0 0 0 N" << endl;
        file << "4-5 0 0 0 0 0 N" << endl;
        file << endl;
    }
    file.close();
}
void Add_File_Information_D(unsigned int id){
    string filename = "Doctor/information/" + to_string(id) + ".txt";
    ofstream file(filename);
    file.close();
}
void Delete_File(const string &tmp_file){
    const char*  file =  tmp_file.c_str();
    if (remove(file) != 0) 
        {
            cout << "Xoa file that bai." <<endl;
        }

}
Manager::Manager(const Account &p):Account(p){
}

bool Manager::Add_Doctor(const string  &user, const string &pass)
{   Account new_Acc;
    string file;
    bool check = new_Acc.Register(user,pass,2);
    if (check){
    Add_File_Schedule_D(new_Acc.get_Id());
    Add_File_Information_D(new_Acc.get_Id());
    }
    return (check);
}
bool Manager::Remove_Doctor(const string &user)
{
    bool check;
    Account tmp;
    check = tmp.Remove_Acc(user,2);
    if (!check){
        return false;
    }

    string file_infor = "Doctor/information/" + to_string(tmp.get_Id()) + ".txt";
    string file_schedule = "Doctor/Schedule/" + to_string(tmp.get_Id()) + ".txt";
    Delete_File(file_infor);
    Delete_File(file_schedule);
 return true;
}
bool Manager::Add_Cashier(const string &user, const string &pass){
    bool check;
    Account tmp;
    check = tmp.Register(user,pass,3);
    if (!check) return false;
   /*Tao file thong tin va lich cho benh nhan*/
    string filename = "Cashier/information/"+to_string(tmp.get_Id()) + ".txt";
    ofstream file(filename);
    file.close();
    return true;
}
bool Manager::Remove_Cashier(const string &user){
bool check;
    Account tmp;
    check = tmp.Remove_Acc(user,3);
    if (!check){
        return false;
    }
    string file_infor = "Cashier/information/" + to_string(tmp.get_Id()) + ".txt";
    Delete_File(file_infor);
 return true;
}
bool Manager::Add_Patient(const string &user,const string &pass){
    bool check;
    Account tmp;

    check = tmp.Register(user,pass,4);
    if (!check) return false;

   /*Tao file thong tin va lich cho benh nhan*/
    string filename = "Patient/information/"+to_string(tmp.get_Id()) + ".txt";
    ofstream file(filename);
    file.close();
    filename = "Patient/Schedule/"+to_string(tmp.get_Id()) + ".txt";
    ofstream file2(filename);
    file2.close();

    return true;
}
bool Manager::Remove_Patient(const string &user)
{
    bool check;
    Account tmp;
    check = tmp.Remove_Acc(user,4);
    if (!check){
        return false;
    }
    string file_infor = "Patient/information/" + to_string(tmp.get_Id()) + ".txt";
    string file_schedule = "Patient/Schedule/" + to_string(tmp.get_Id()) + ".txt";
    Delete_File(file_infor);
    Delete_File(file_schedule);
 return true;
}
Manager::~Manager()
{
}