#include <iostream>

int main() {
    int num_of_keys, num_of_presses, elem;
    int *keys;
    std::cin >> num_of_keys;
    keys = new int[num_of_keys];
    for (int i = 0; i < num_of_keys; ++i) {
        std::cin >> elem;
        keys[i] = elem;
    }
    std::cin >> num_of_presses;
    for (int i = 0; i < num_of_presses; ++i) {
        std::cin >> elem;
        keys[elem - 1]--;
    }
    for (int i = 0; i < num_of_keys; ++i) {
        if (keys[i] < 0) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    delete[] keys;
}
