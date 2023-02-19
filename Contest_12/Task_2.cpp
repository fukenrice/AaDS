#include <iostream>
#include <vector>
#include <algorithm>

u_int64_t largestRectangleArea(std::vector<u_int64_t> *heights) {
    std::vector<u_int64_t> unique;
    for (u_int64_t i = 0; i < heights->size(); ++i) {
        unique.emplace_back(heights->at(i));
    }
    std::sort(unique.begin(), unique.end());
    auto new_end = std::unique(unique.begin(), unique.end());
    unique.erase(new_end, unique.end());
    u_int64_t max = 0;
    for (u_int64_t index = 0; index < unique.size(); ++index) {
        u_int64_t width = 0;
        u_int64_t max_width = 1;
        for (u_int64_t j = 0; j < heights->size(); ++j) {
            if (heights->at(j) >= unique.at(index)) {
                width++;
            } else {
                max_width = std::max(max_width, width);
                width = 0;
            }
        }
        max_width = std::max(max_width, width);
        max = std::max(max_width * unique.at(index), max);
    }
    return max;
}

int main() {
    u_int64_t num, elem;
    std::vector<u_int64_t> vect;
    std::cin >> num;
    for (u_int64_t i = 0; i < num; ++i) {
        std::cin >> elem;
        vect.emplace_back(elem);
    }
    std::cout << largestRectangleArea(&vect);
    return 0;
}
