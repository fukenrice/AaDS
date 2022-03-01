#include <iostream>
#include <vector>

void binarySearch(int value, const std::vector<int> &vect) {
    int index;
    int left = -1, right = vect.size();
    while (right - left > 1) {
        index = (left + right) / 2;
        if (vect.at(index) < value) {
            left = index;
        } else {
            right = index;
        }
    }
    int left_r = -1, right_r = vect.size();
    while (right_r - left_r > 1) {
        index = (left_r + right_r) / 2;
        if (vect.at(index) <= value) {
            left_r = index;
        } else {
            right_r = index;
        }
    }
    if (left == left_r && right_r == right) {
        std::cout << 0 << std::endl;
        return;
    }
    if (right == left_r) {
        std::cout << right + 1 << " " << right + 1 << std::endl;
    } else {
        std::cout << right + 1 << " " << left_r + 1 << std::endl;
    }
}

int main() {
    int sorted_num, not_sorted_num, element;
    std::vector<int> first;
    std::cin >> sorted_num >> not_sorted_num;
    for (int i = 0; i < sorted_num; ++i) {
        std::cin >> element;
        first.emplace_back(element);
    }
    for (int i = 0; i < not_sorted_num; ++i) {
        std::cin >> element;
        binarySearch(element, first);
    }
    return 0;
}
