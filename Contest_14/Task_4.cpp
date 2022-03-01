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
    int swaps = 0;
    for (int iter = 1; iter < num; ++iter) {
        if (vect.at(iter - 1) > vect.at(iter)) {
            int left = -1, right = iter;
            while (right - left > 1) {
                int index = (left + right) / 2;
                if (vect.at(index) <= vect.at(iter)) {
                    left = index;
                } else {
                    right = index;
                }
            }
            for (int j = iter; j > right; --j) {
                std::swap(vect.at(j), vect.at(j - 1));
                swaps++;
            }
        }
    }
    for (int i = 0; i < num; ++i) {
        std::cout << vect.at(i) << " ";
    }
    std::cout << std::endl << swaps;
    return 0;
}


void insertionSort(std::vector<int> vect, int size) {
    for (int iter = 1; iter < num; ++iter) {
        if (vect.at(iter - 1) > vect.at(iter)) {
            int left = -1, right = iter;
            while (right - left > 1) {
                int index = (left + right) / 2;
                if (vect.at(index) <= vect.at(iter)) {
                    left = index;
                } else {
                    right = index;
                }
            }
            for (int j = iter; j > right; --j) {
                std::swap(vect.at(j), vect.at(j - 1));
                swaps++;
            }
        }
    }
}
