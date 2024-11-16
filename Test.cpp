#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Test bắt đầu..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "1 giây đã trôi qua." << std::endl;
    return 0;
}
