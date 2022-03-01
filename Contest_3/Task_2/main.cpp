#include <iostream>
#include <string>

std::string GenerateTableLine(std::string prev_line, int cells_num) {
    std::string cur_line;
    std::string next_line = "|";
    for (int i = 0; i < cells_num; ++i) {
        int cell_range;
        std::cin >> cell_range;
        for (int j = 0; j < cell_range; ++j) {
            next_line += ' ';
        }
        next_line += '|';
    }
    if (prev_line.length() > next_line.length()) {
        for (int i = 0; i < prev_line.length(); ++i) {
            if (prev_line.at(i) == '|') {
                cur_line += '+';
            } else {
                cur_line += '-';
            }
        }
    } else {
        for (int i = 0; i < next_line.length(); ++i) {
            if (next_line.at(i) == '|') {
                cur_line += '+';
            } else {
                cur_line += '-';
            }
        }
    }
    if (prev_line.length() <= next_line.length()) {
        for (int i = 0; i < prev_line.length(); ++i) {
            if (prev_line.at(i) == '|') {
                cur_line.at(i) = '+';
            }
        }
    } else {
        for (int i = 0; i < next_line.length(); ++i) {
            if (next_line.at(i) == '|') {
                cur_line.at(i) = '+';
            }
        }
    }
    std::cout << cur_line << std::endl << next_line << std::endl;
    return next_line;
}




int main() {
    int N;
    int cell_num;
    std::cin >> N;
    std::string str = "+";
    std::cin >> cell_num;
    for (int i = 0; i < cell_num; ++i) {
        int cnt;
        std::cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            str += '-';
        }
        str += '+';
    }
    std::cout << str << std::endl;
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == '+') {
            str.at(i) = '|';
        } else {
            str.at(i) = ' ';
        }
    }
    std::cout << str << std::endl;
    for (int i = 1; i < N; ++i) {
        std::cin >> cell_num;
        str = GenerateTableLine(str, cell_num);
    }
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == '|') {
            str.at(i) = '+';
        } else {
            str.at(i) = '-';
        }
    }
    std::cout << str;
    return 0;
}
