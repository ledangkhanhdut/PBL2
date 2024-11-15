#include <iostream>
#include <unistd.h>  // Để sử dụng hàm sleep trên Linux và macOS
#include <windows.h> // Để sử dụng Sleep() trên Windows

void gotoxy(int x, int y) {
    // Di chuyển con trỏ đến vị trí (x, y) trong console
    std::cout << "\033[" << y << ";" << x << "H";
}

void drawSquareBoard(int size) {
    for (int row = 0; row < size * 2 + 1; ++row) {
        if (row % 2 == 0) { // Dòng ngang
            std::cout << "+";
            for (int col = 0; col < size; ++col) {
                std::cout << "---+";
            }
            std::cout << std::endl;
        } else { // Dòng dọc
            std::cout << "|";
            for (int col = 0; col < size; ++col) {
                std::cout << "   |";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int size = 3; // Kích thước bảng vuông 3x3
    drawSquareBoard(size);

    // Đưa con trỏ vào một ô cụ thể, ví dụ: ô (2, 2) của bảng
    int x = 4;   // Cột 4 trong bảng
    int y = 3;   // Dòng 3 trong bảng
    gotoxy(x, y);
    
    std::cout << "X"; // In ký tự vào vị trí ô mong muốn

    // Để console không đóng ngay lập tức
    #ifdef _WIN32
        Sleep(5000); // Windows: dừng lại 5 giây
    #else
        sleep(5);    // Linux/macOS: dừng lại 5 giây
    #endif

    return 0;
}
