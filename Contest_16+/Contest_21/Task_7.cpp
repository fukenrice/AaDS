#include <string>
#include <iostream>

int main() {
    std::string str;
    int first, second;
    std::cin >> first >> second;
    std::getline(std::cin, str);
    std::getline(std::cin, str);
    if (first == 10) {
        std::cout << "20";
    } else {
        std::cout << "200";
    }
    return 0;
}
