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
    for (int i = 0; i < num - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < num; ++j) {
            if (vect.at(j) < vect.at(min)) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(vect.at(i), vect.at(min));
            swaps++;
        }
    }
    for (int i = 0; i < num; ++i) {
        std::cout << vect.at(i) << " ";
    }
    std::cout << std::endl << swaps;
    return 0;
}


void selectionSort(std::vector<int> vect, size) {
    for (int i = 0; i < num - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < num; ++j) {
            if (vect.at(j) < vect.at(min)) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(vect.at(i), vect.at(min));
            swaps++;
        }
    }
}
