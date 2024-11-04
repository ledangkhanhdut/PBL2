#include <iostream>
#include <string>

int main() {
    std::string inputString;

    std::cout << "Nhập vào một chuỗi có chứa ký tự trắng: ";
    std::getline(std::cin, inputString); // Dùng getline để lấy cả dòng

    std::cout << "Chuỗi vừa nhập: " << inputString << std::endl;

    return 0;
}
