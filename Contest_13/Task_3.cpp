#include <iostream>
#include <vector>

bool canSplit(int size, int num, const std::vector<int> &sections) {
    int count = 0;
    for (int i = 0; i < sections.size(); ++i) {
        count += sections.at(i) / size;
    }
    return count >= num;
}

int main() {
    int num_of_sections, num_of_res, element, max = 0;
    std::vector<int> sections;
    std::cin >> num_of_sections >> num_of_res;
    for (int i = 0; i < num_of_sections; ++i) {
        std::cin >> element;
        if (element > max) {
            max = element;
        }
        sections.emplace_back(element);
    }
    int size, left = -1, right = max + 1;
    bool flag = false;
    while (right - left > 1) {
        size = (left + right) / 2;
        if (canSplit(size, num_of_res, sections)) {
            left = size;
            flag = true;
        } else {
            right = size;
        }
    }
    if (flag) {
        std::cout << (left + right) / 2;
    } else {
        std::cout << 0;
    }
    return 0;
}
