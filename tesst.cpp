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
    cout << "|  Hay nhap yeu cau cua ban :                                   |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;

    // Ðua con tr? tr? l?i v? trí nh?p choice ngay sau câu "Hay nhap yeu cau cua ban :"
    cout << "\033[2A"; // Di chuy?n lên 6 dòng
    cout << "\033[32C"; // Di chuy?n con tr? sang ph?i 36 ký t?
    cin >> choice;

    return 0;
}

