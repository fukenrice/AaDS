#include <iostream>

int *countSort(const int *arr, int num, int min, int max) {
    int *counts, *res;
    res = new int[num];
    for (int i = 0; i < num; ++i) {
        res[i] = 0;
    }
    counts = new int[max - min + 1];
    for (int i = 0; i < max - min + 1; ++i) {
        counts[i] = 0;
    }
    // Подсчитываем количество чисел.
    for (int i = 0; i < num; ++i) {
        counts[arr[i] - min]++;
    }
    // Считаем, сколько чисел меньше или равных текущему.
    // Должно быть больших
    for (int i = max - min; i >= 1; --i) {
        counts[i - 1] += counts[i];
    }
    // Расставляем числа в массив
    for (int i = num - 1; i >= 0; --i) {
        counts[arr[i] - min]--;
        res[counts[arr[i] - min]] = arr[i];
    }
    delete[] counts;
    return res;
}


int main() {
    int *arr, *res;
    int min = 10000000, max = -10000000;
    int num, elem;
    std::cin >> num;
    arr = new int[num];
    for (int i = 0; i < num; ++i) {
        arr[i] = 0;
    }
    for (int i = 0; i < num; ++i) {
        std::cin >> elem;
        arr[i] = elem;
        if (elem < min) {
            min = elem;
        }
        if (elem > max) {
            max = elem;
        }
    }
    res = countSort(arr, num, min, max);
    for (int i = 0; i < num; ++i) {
        std::cout << res[i] << " ";
    }
    delete[] arr;
    delete[] res;
    return 0;
}
