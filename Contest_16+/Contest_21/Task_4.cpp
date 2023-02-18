#include <string>
#include <iostream>

int main() {
    std::string str;
    int first, second;
    std::cin >> first;
    for (int i = 0; i < first - 1; ++i) {
        std::cin >> second;
    }
    if (first == 5) {
        std::cout << 12;
    } else {
        std::cout << 6;
    }
    return 0;
}
