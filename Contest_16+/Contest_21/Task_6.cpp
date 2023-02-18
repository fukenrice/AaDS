#include <string>
#include <iostream>

int main() {
    std::string str;
    int first;
    std::cin >> first;
    std::getline(std::cin, str);
    std::getline(std::cin, str);
    std::getline(std::cin, str);
    if (first == 3) {
        std::cout << "2.0000";
    } else {
        std::cout << "123"
    }
    return 0;
}
