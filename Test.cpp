#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int choice;

    cout << "+--------------------------------------------------------------+" << endl;
    cout << "|           Giao dien dang ky va dang nhap.                    |" << endl;
    cout << "|  1.Dang Ky                                                   |" << endl;
    cout << "|  2.Dang Nhap                                                 |" << endl;
    cout << "|  3.Thoat.                                                    |" << endl;
    cout << "|  Hay nhap yeu cau cua ban :                                  |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;

    // Đưa con trỏ trở lại vị trí nhập choice ngayda sau câu "Hay nhap yeu cau cua ban :"
    cout << "\033[2A"; // Di chuyển lên 6 dòng
    cout << "\033[31C"; // Di chuyển con trỏ sang phải 36 ký tự
    cin >> choice;

    return 0;
}