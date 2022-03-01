#include <iostream>
#include <string>

std::string GetUniqueChars(const std::string &str) {
    std::string unique_chars;
    bool unique = false;
    for (int i = 0; i < str.length(); ++i) {
        unique = true;
        if (unique_chars.length() == 26) {
            break;
        }
        for (int j = 0; j < unique_chars.length(); ++j) {
            if (str.at(i) == unique_chars.at(j)) {
                unique = false;
                break;
            }
        }
        if (unique) {
            unique_chars += str.at(i);
        }
    }
    return unique_chars;
}


std::string GetDifference(std::string s1, std::string s2) {
    std::string unique_in_first = GetUniqueChars(s1);
    std::string unique_in_second = GetUniqueChars(s2);
    std::string different_chars = unique_in_first + unique_in_second;
    for (int i = different_chars.length() - 1; i >= 0 ; --i) {
        if (different_chars.at(i) == ' ') {
            different_chars.erase(i, 1);
        }
    }
    for (int i = 0; i < different_chars.length(); ++i) {
        for (int j = 0; j < different_chars.length() - 1; ++j) {
            if (different_chars.at(j) > different_chars.at(j + 1)) {
                char tmp = different_chars.at(j);
                different_chars.at(j) = different_chars.at(j + 1);
                different_chars.at(j + 1) = tmp;
            }
        }
    }

    std::string del;

    for (int i = different_chars.length() - 1; i > 0 ; --i) {
        if (different_chars.at(i) == different_chars.at(i - 1)) {
            del += different_chars.at(i);
            different_chars.erase(i, 1);
        }
    }

    for (int i = different_chars.length() - 1; i >= 0; --i) {
        for (int j = 0; j < del.length(); ++j) {
            if (different_chars.at(i) == del.at(j)) {
                different_chars.erase(i, 1);
                break;
            }
        }
    }

    return different_chars;
}

int main() {
    std::string s1, s2, result;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    result = GetDifference(s1, s2);
    if (result.length() == 0) {
        std::cout << "NONE";
    } else {
        for (int i = 0; i < result.length(); ++i) {
            std::cout << result.at(i) << ' ';
        }
    }
    return 0;
}
