#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

int main() {
    int num, size, min, input;
    std::cin >> num >> size;

    // Решим задачу с помощью двух стеков.
    // В них будут храниться пары (число | минимальный элемент в стеке).
    // Добавлять элементы будем в первый стек,
    // убирать из второго (если второй пустой,
    // добавляем в него элементы из первого)(получится механизм очереди).
    std::stack<std::pair<int, int>> first, second;

    for (int index = 0; index < num; ++index) {
        std::cin >> input;

        if (index >= size) {
            // Если второй стек пустой, то добавляем в него элементы первого
            // и удаляем первый(последний в первом стеке).
            if (second.empty()) {
                while (!first.empty()) {
                    int element = first.top().first;
                    first.pop();
                    min = second.empty() ? element : std::min(element, second.top().second);
                    second.push(std::make_pair(element, min));
                }
            }
            second.pop();

            // Добавляем новый эелемент.
            min = first.empty() ? input : std::min(input, first.top().second);
            first.push(std::make_pair(input, min));
            // Находим минимум и выводим.
            if (first.empty() || second.empty()) {
                min = first.empty() ? second.top().second : first.top().second;
            } else {
                min = std::min(first.top().second, second.top().second);
            }
            std::cout << min << std::endl;

        } else if (index == size - 1) {
            min = first.empty() ? input : std::min(input, first.top().second);
            first.push(std::make_pair(input, min));
            // Находим минимум и выводим его.
            if (first.empty() || second.empty()) {
                min = first.empty() ? second.top().second : first.top().second;
            } else {
                min = std::min(first.top().second, second.top().second);
            }
            std::cout << min << std::endl;
        } else {
            // Добавляем элемент в стек. (если стек пустой, то минимальный элемент -
            // это введенный, иначе - минимум = минимум из предыдущего минимума
            // и введенного элемента).
            min = first.empty() ? input : std::min(input, first.top().second);
            first.push(std::make_pair(input, min));
        }
    }
}
