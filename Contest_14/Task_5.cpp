#include <iostream>
#include <vector>
#include <utility>

int main() {
    std::vector<int> workers;
    int elem;
    while (std::cin >> elem) {
        workers.push_back(elem);
        char c = std::cin.get();
        if (c == '\n') {
            break;
        }
    }

    std::vector<int> prices;
    while (std::cin >> elem) {
        prices.push_back(elem);
        char c = std::cin.get();
        if (c == '\n') {
            break;
        }
    }

    for (int i = 1; i < workers.size(); ++i) {
        int j = i;
        while (j >= 1 && workers.at(j - 1) > workers.at(j)) {
            std::swap(workers.at(j - 1), workers.at(j));
            j--;
        }
    }

    for (int i = 1; i < prices.size(); ++i) {
        int j = i;
        while (j >= 1 && prices.at(j - 1) < prices.at(j)) {
            std::swap(prices.at(j - 1), prices.at(j));
            j--;
        }
    }

    int64_t res = 0;
    for (int i = 0; i < prices.size(); ++i) {
        res += workers.at(i) * prices.at(i);
    }
    std::cout << res;
    return 0;
}
