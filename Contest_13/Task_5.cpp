#include <iostream>
#include <complex>

int main() {
    double res;
    std::cin >> res;
    std::cout << std::fixed;
    std::cout.precision(9);
    double num, left = 0, right = 1e10;
    while (right - left > 10e-10) {
        num = (left + right) / 2;
        if (num * num + std::sqrt(num) >= res) {
            right = num;
        } else {
            left = num;
        }
    }
    std::cout << left;
    return 0;
}
