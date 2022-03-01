#include <iostream>
#include <vector>
#include <utility>

int main() {
    int num, element;
    std::cin >> num;
    std::vector<int> vect;
    for (int i = 0; i < num; ++i) {
        std::cin >> element;
        vect.emplace_back(element);
    }
    int last_swap = -1;
    int iter = 0, swaps = 0;
    while (last_swap != 0) {
        last_swap = 0;
        for (int i = 0; i < num - iter - 1; ++i) {
            if (vect.at(i) > vect.at(i + 1)) {
                std::swap(vect.at(i), vect.at(i + 1));
                last_swap = i + 1;
                swaps++;
            }
        }
        iter++;
    }
    for (int i = 0; i < num; ++i) {
        std::cout << vect.at(i) << " ";
    }
    std::cout << std::endl << swaps;
    return 0;
}


void bubbleSort(std::vector<int> vect, size) {
    int last_swap = -1;
    int iter = 0, swaps = 0;
    while (last_swap != 0) {
        last_swap = 0;
        for (int i = 0; i < num - iter - 1; ++i) {
            if (vect.at(i) > vect.at(i + 1)) {
                std::swap(vect.at(i), vect.at(i + 1));
                last_swap = i + 1;
                swaps++;
            }
        }
        iter++;
    }
}
