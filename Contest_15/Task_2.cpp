#include <iostream>

int64_t *radixSort(int64_t *arr, int num, int64_t max) {
    int64_t *res;
    int64_t byte = 1;
    res = new int64_t[num];
    for (int i = 0; i < num; ++i) {
        res[i] = 0;
    }
    while (max / byte > 0) {
        int counts[256] = {0};
        // Подсчитываем количество i-ых байт.
        for (int i = 0; i < num; ++i) {
            counts[arr[i] / byte % 256]++;
        }
        // Резервируем места.
        for (int i = 1; i < 256; ++i) {
            counts[i] += counts[i - 1];
        }
        // Заполняем результат.
        for (int i = num - 1; i >= 0; --i) {
            counts[arr[i] / byte % 256]--;
            res[counts[arr[i] / byte % 256]] = arr[i];
        }
        // Переносим данные в исходный массив для сортировки по след байту.
        for (int i = 0; i < num; ++i) {
            arr[i] = res[i];
        }
        // Сдвигаем указатель на следующий байт, для сортировки по нему.
        byte *= 256;
    }
    return res;
}

int main() {
    int num;
    std::cin >> num;
    int64_t elem, max = -1;
    int64_t *arr, *res;
    arr = new int64_t[num];
    for (int i = 0; i < num; ++i) {
        std::cin >> elem;
        if (elem > max) {
            max = elem;
        }
        arr[i] = elem;
    }
    res = radixSort(arr, num, max);
    for (int i = 0; i < num; ++i) {
        std::cout << res[i] << " ";
    }

    delete[] arr;
    delete[] res;
    return 0;
}
