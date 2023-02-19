#include <iostream>
#include <vector>
#include <utility>

int deleteSameRange(std::vector<std::pair<int, int>> *vect, int start) {
    int element = vect->at(start).first;
    auto iter = vect->cbegin();
    int deleted = 0;
    while (!vect->empty() && vect->size() > start && element == vect->at(start).first) {
        vect->erase(iter + start);
        deleted++;
    }
    if (vect->empty()) {
        return deleted;
    }
    int next_start = start == 0 ? 0 : start - vect->at(start - 1).second;
    int cnt = 1;
    int index = next_start;
    while (index + 1 != vect->size() && vect->at(index).first == vect->at(index + 1).first) {
        cnt++;
        vect->at(index + 1).second = vect->at(index).second + 1;
        index++;
    }
    if (cnt >= 3) {
        deleted += deleteSameRange(vect, next_start);
    }
    return deleted;
}

int main() {
    // Первое в паре - это цвет, второе - колво повторений подряд, включая текущий.
    std::vector<std::pair<int, int>> vect;
    int num, input, start = -1;
    std::cin >> num;
    for (int index = 0; index < num; ++index) {
        std::cin >> input;
        if (vect.empty()) {
            vect.emplace_back(input, 1);
        } else {
            if (vect.back().first == input) {
                if (vect.back().second == 2) {
                    start = index - 2;
                }
                vect.emplace_back(input, vect.back().second + 1);
            } else {
                vect.emplace_back(input, 1);
            }
        }
    }
    if (start != -1) {
        std::cout << deleteSameRange(&vect, start);
    } else {
        std::cout << 0;
    }
    return 0;
}
