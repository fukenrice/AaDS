#include <iostream>

struct Drone {
    int id;
    int64_t weight;
    Drone(int id, int64_t weight) {
        this->id = id;
        this->weight = weight;
    }
};

Drone **radixSort(Drone **arr, int num, int64_t max) {
    Drone **res;
    int64_t byte = 1;
    res = new Drone *[num];
    for (int i = 0; i < num; ++i) {
        res[i] = nullptr;
    }
    while (max / byte > 0) {
        int counts[256] = {0};
        // Подсчитываем количество i-ых байт.
        for (int i = 0; i < num; ++i) {
            counts[arr[i]->weight / byte % 256]++;
        }
        // Резервируем места(по убыванию).
        for (int i = 255; i >= 1; --i) {
            counts[i - 1] += counts[i];
        }
        // Заполняем результат.
        for (int i = num - 1; i >= 0; --i) {
            counts[arr[i]->weight / byte % 256]--;
            res[counts[arr[i]->weight / byte % 256]] = arr[i];
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
    int id;
    int64_t weight, max = -1;
    auto **arr = new Drone *[num];
    Drone **res;

    for (int i = 0; i < num; ++i) {
        std::cin >> id >> weight;
        if (weight > max) {
            max = weight;
        }
        auto *elem = new Drone(id, weight);
        arr[i] = elem;
    }
    res = radixSort(arr, num, max);
    for (int i = 0; i < num; ++i) {
        std::cout << arr[i]->id << "\t" << arr[i]->weight << std::endl;
        delete arr[i];
    }

    delete[] res;
    delete[] arr;
}
