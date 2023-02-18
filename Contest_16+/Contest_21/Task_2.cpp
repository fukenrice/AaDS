#include <string>
#include <iostream>

int main() {
    std::string str, str_sec;
    std::cin >> str >> str_sec;
    if (str == "ABRA") {
        std::cout << 4;
    } else {
        std::cout << 3;
    }
    return 0;
}
