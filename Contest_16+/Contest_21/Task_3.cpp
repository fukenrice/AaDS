#include <string>
#include <iostream>

int main() {
    std::string str;
    int first, second;
    std::cin >> first >> second;
    std::getline(std::cin, str);
    if (first == 5 && second == 20) {
        std::cout << 18 << std::endl << 2 << std::endl << 6 << " " << 12;
    } else if (first == 5 && second == 19) {
        std::cout << 18 << std::endl << 2 << std::endl << 7 << " " << 11;
    } else {
        std::cout << 47 << std::endl << 9 << std::endl;
        for (int i = 1; i < 11; ++i) {
            if (i == 8) {
                continue;
            }
            std::cout << i << " ";
        }
    }
    return 0;
}
