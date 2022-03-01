#include <iostream>
#include <string>

std::string GetSequenceElement(std::string cur_element, int n) {
    std::string next_element;

    for (int i = 0; i < n - 1; ++i) {
        int cnt = 1;
        if (cur_element.length() == 1) {
            next_element.append(std::to_string(cnt) + cur_element);
            cur_element = next_element;
            next_element = "";
            continue;
        }
        for (int j = 1; j < cur_element.length(); ++j) {
            if (cur_element.at(j) == cur_element.at(j - 1)) {
                cnt++;
            }
            if (cur_element.at(j) != cur_element.at(j - 1)) {
                next_element.append(std::to_string(cnt) + cur_element.at(j - 1));
                cnt = 1;
            }
            if (j == cur_element.length() - 1) {
                next_element.append(std::to_string(cnt) + cur_element.at(j));
                cnt = 1;
            }
        }
        cur_element = next_element;
        next_element = "";
    }
    return cur_element;
}

int main() {
    std::string first_element;
    int N;
    std::cin >> first_element >> N;
    std::cout << GetSequenceElement(first_element, N);
    return 0;
}
