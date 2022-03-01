#include <iostream>
#include <string>

std::string Decode(std::string str) {
    std::string res;
    str.erase(str.length() - 1, 1);

    for (int i = 0; i < str.length(); i += 2) {
        res += str.at(i);
    }
    if (str.length() % 2 == 0) {
        for (int i = str.length() - 1; i >= 0; i -= 2) {
            res += str.at(i);
        }
    } else {
        for (int i = str.length() - 2; i >= 1; i -= 2) {
            res += str.at(i);
        }
    }

    return res;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << Decode(str);
    return 0;
}
