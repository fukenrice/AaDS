#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void heapify(std::vector<std::pair<int, int>> *heap, int index, int size) {
    int left, right, largest = -1;
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (left < size && heap->at(left).first > heap->at(largest).first) {
        largest = left;
    }
    if (right < size && heap->at(right).first > heap->at(largest).first) {
        largest = right;
    }
    if (largest != index) {
        std::swap(heap->at(index), heap->at(largest));
        heapify(heap, largest, size);
    }
}

void heapSort(std::vector<std::pair<int, int>> *heap, int size) {
    for (int i = size / 2; i >= 0; --i) {
        heapify(heap, i, size);
    }
    for (int i = size - 1; i >= 0; --i) {
        std::swap(heap->at(0), heap->at(i));
        heapify(heap, 0, i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // 1 - расстояние, 2 - индекс
    std::vector<std::pair<int, int>> cities;
    std::vector<std::pair<int, int>> shelters;
    int num_of_cities, num_of_shelters, elem;
    int *res;
    std::cin >> num_of_cities;
    res = new int[num_of_cities];
    for (int i = 0; i < num_of_cities; ++i) {
        std::cin >> elem;
        cities.emplace_back(std::make_pair(elem, i));
    }
    std::cin >> num_of_shelters;
    for (int i = 0; i < num_of_shelters; ++i) {
        std::cin >> elem;
        shelters.emplace_back(std::make_pair(elem, i + 1));
    }
    heapSort(&cities, num_of_cities);
    heapSort(&shelters, num_of_shelters);
    int city_ptr = 0, shelter_ptr = 0;
    for (int index = 0; index < num_of_cities; ++index) {
        if (shelter_ptr == num_of_shelters - 1) {
            res[cities.at(city_ptr++).second] = shelters.at(shelter_ptr).second;
            continue;
        }
        while (shelter_ptr != num_of_shelters - 1 &&
               std::abs(cities.at(city_ptr).first - shelters.at(shelter_ptr).first) >
                   std::abs(cities.at(city_ptr).first - shelters.at(shelter_ptr + 1).first)) {
            shelter_ptr++;
        }
        res[cities.at(city_ptr).second] = shelters.at(shelter_ptr).second;
        city_ptr++;
    }
    for (int i = 0; i < num_of_cities; ++i) {
        std::cout << res[i] << " ";
    }
    delete[] res;
    return 0;
}
