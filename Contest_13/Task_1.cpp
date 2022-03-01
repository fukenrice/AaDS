#include <iostream>

int main() {
    int element, max = -1, second_max = -1;

    std::cin >> element;

    while (element != 0) {
        if (element >= max) {
            second_max = max;
            max = element;
        } else {
            if (element >= second_max) {
                second_max = element;
            }
        }
        std::cin >> element;
    }
    std::cout << max << std::endl << second_max;
    return 0;
}
