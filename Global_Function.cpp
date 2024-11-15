#include "Global_Function.h"

void Design(){
    cout << " ________________________________________________________________" << endl;
    cout << "|								 |" << endl;
    cout << "|               PBL2: DU AN CO SO LAP TRINH                      |" << endl;
    cout << "|       TEN CHU DE: UNG DUNG QUAN LY DAT LICH KHAM BENH          |" << endl;
    cout << "|-----------------------------GVHD-------------------------------|" << endl;
    cout << "|  		       TRAN HO THUY TIEN		         |" << endl;	
    cout << "|------------------------SV THUC HIEN----------------------------|" << endl;
    cout << "|-------HO VA TEN------------------------------LSH---------------|" << endl;
    cout << "|     	NGUYEN DINH HIEN	|   	    23T_NHAT1		 |" << endl;
    cout << "|     	LE DANG KHANH        	|   	    23T_NHAT1  		 |" << endl;
    cout << "|_______________________________|________________________________|" << endl;
    
    cout << endl;
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
string getCurrentDate()
{
    auto now = chrono::system_clock::now();                 // Lấy thời gian hiện tại
    time_t now_time = chrono::system_clock::to_time_t(now); // Chuyển đổi thành time_t

    tm *ltm = localtime(&now_time); // Lấy thông tin thời gian

    ostringstream oss;
    oss << put_time(ltm, "%d-%m-%Y"); // Định dạng ngày tháng dạng dd/mm/yyyy

    return oss.str(); // Trả về chuỗi ngày tháng
}

string add_day(const string &day_m_y, int day)
{
    istringstream dateStream(day_m_y);
    int d, m, y;
    char separator;

    dateStream >> d >> separator >> m >> separator >> y;

    // Thiết lập đối tượng `tm`
    tm date = {};
    date.tm_mday = d;
    date.tm_mon = m - 1;     // Tháng trong `tm` bắt đầu từ 0 (tháng 1 là 0)
    date.tm_year = y - 1900; // Năm trong `tm` bắt đầu từ 1900

    // Thêm số ngày vào
    date.tm_mday += day;

    // Chuẩn hóa thời gian
    mktime(&date);

    // Tạo chuỗi kết quả dạng "day-month-year"
    ostringstream result;
    result << setw(2) << setfill('0') << date.tm_mday << "-"
           << setw(2) << setfill('0') << (date.tm_mon + 1) << "-"
           << (date.tm_year + 1900);

    return result.str();
}
int calculateDayDifference(const string &dateAfter, const string &dateBefore) {
    int dayAfter, monthAfter, yearAfter;
    int dayBefore, monthBefore, yearBefore;

    // Tách ngày, tháng, năm của dateAfter
    sscanf(dateAfter.c_str(), "%d-%d-%d", &dayAfter, &monthAfter, &yearAfter);

    // Tách ngày, tháng, năm của dateBefore
    sscanf(dateBefore.c_str(), "%d-%d-%d", &dayBefore, &monthBefore, &yearBefore);

    // Tạo struct tm cho dateAfter
    tm tmAfter = {};
    tmAfter.tm_mday = dayAfter;
    tmAfter.tm_mon = monthAfter - 1; // tháng trong struct tm bắt đầu từ 0
    tmAfter.tm_year = yearAfter - 1900; // năm trong struct tm bắt đầu từ 1900

    // Tạo struct tm cho dateBefore
    tm tmBefore = {};
    tmBefore.tm_mday = dayBefore;
    tmBefore.tm_mon = monthBefore - 1;
    tmBefore.tm_year = yearBefore - 1900;

    // Chuyển struct tm sang thời gian tính bằng giây
    time_t timeAfter = mktime(&tmAfter);
    time_t timeBefore = mktime(&tmBefore);

    // Tính số ngày chênh lệch
    double differenceInSeconds = difftime(timeAfter, timeBefore);
    int dayDifference = differenceInSeconds / (60 * 60 * 24);

    return dayDifference;
}
void  String_processing(string &str){
    string tmp_string;
    size_t start = str.find_first_not_of(" ");  
    size_t end = str.find_last_not_of(" ");     
    
    if (start == string::npos || end == string::npos) {
        str = "";  
        return;
    }
    
    str = str.substr(start, end - start + 1);  // Cắt chuỗi để loại bỏ khoảng trắng thừa

    // Chuyển chữ cái đầu tiên của mỗi từ thành chữ hoa và các chữ còn lại thành chữ thường
    bool newWord = true;
    for (char &c : str) {
        if (isspace(c)) {
            newWord = true;  // Đánh dấu từ mới
        } else if (newWord) {
            c = toupper(c);  // Chữ cái đầu tiên của từ chuyển thành hoa
            newWord = false;
        } else {
            c = tolower(c);  // Các chữ cái còn lại trong từ chuyển thành thường
        }
    }

    int i = 1;
     while (i<str.size())
     { 
      if (str[i] == ' ' && str[i-1] ==' ') str.erase(i,1) ; else i++;
     
     }
     for (int i = 0; i < str.size(); i++)
     if (str[i] == ' ')
            tmp_string = tmp_string + '-';
        else
            tmp_string = tmp_string + str[i];
    str = tmp_string;
}

void removeDashes(string &str){
    string tmp_str ="";
    for (int i = 0 ; i < str.size(); i++) 
    if (str[i] == '-')
        tmp_str = tmp_str + ' ';
        else
        tmp_str = tmp_str + str[i];
    str = tmp_str;
}

string Extral_Status(char Status){
    if (Status == 'N') return "Chua Kham";
    else return "Da Kham";

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