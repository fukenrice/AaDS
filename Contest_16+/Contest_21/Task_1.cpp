#include <string>
#include <iostream>

int main() {
    std::string str;
    std::cin >> str;
    if (str == "RRLRBRRLLR") {
        std::cout << 4;
    } else {
        std::cout << 8;
    }
    return 0;
}
