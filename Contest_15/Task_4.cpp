#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int arr[26];
    for (int i = 0; i < 26; ++i) {
        arr[i] = 0;
    }
    int num;
    std::string first_part;
    char elem;
    std::cin >> num;
    for (int i = 0; i < num; ++i) {
        std::cin >> elem;
        arr[static_cast<int>(elem) - 65]++;
    }
    std::string first_solo;
    for (int i = 0; i < 26; ++i) {
        while (arr[i] / 2 > 0) {
            first_part += i + 65;
            arr[i] -= 2;
        }
        if (arr[i] == 1 && first_solo.empty()) {
            first_solo = i + 65;
        }
    }

    std::string second_part(first_part);
    std::reverse(second_part.begin(), second_part.end());
    if (!first_solo.empty()) {
        first_part += first_solo;
    }
    first_part += second_part;
    std::cout << first_part;
    return 0;
}
