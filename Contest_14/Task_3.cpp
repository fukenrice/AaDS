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
    int elems = 0;

    for (int i = 1; i < num; ++i) {
        int j = i;
        while (j >= 1 && vect.at(j - 1) > vect.at(j)) {
            std::swap(vect.at(j - 1), vect.at(j));
            j--;
        }
        if (j == i) {
            elems++;
        }
    }
    for (int i = 0; i < num; ++i) {
        std::cout << vect.at(i) << " ";
    }
    std::cout << std::endl << elems;
    return 0;
}


