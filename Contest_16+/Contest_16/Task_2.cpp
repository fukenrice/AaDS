#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void heapify(std::vector<int> *heap, int index, int size) {
    int left, right, largest = -1;
    left = 2 * index + 1;
    right = 2 * index + 2;
    largest = index;
    if (left < size && heap->at(left) > heap->at(largest)) {
        largest = left;
    }
    if (right < size && heap->at(right) > heap->at(largest)) {
        largest = right;
    }
    if (largest != index) {
        std::swap(heap->at(index), heap->at(largest));
        heapify(heap, largest, size);
    }
}

void heapSort(std::vector<int> *heap, int size) {
    for (int i = size / 2; i >= 0; --i) {
        heapify(heap, i, size);
    }
    for (int i = size - 1; i >= 0; --i) {
        std::swap(heap->at(0), heap->at(i));
        heapify(heap, 0, i);
    }
}

int main() {
    int num, elem;
    std::cin >> num;
    std::vector<int> heap;
    for (int i = 0; i < num; ++i) {
        std::cin >> elem;
        heap.emplace_back(elem);
    }
    heapSort(&heap, num);
    for (int i = 0; i < num; ++i) {
        std::cout << heap.at(i) << " ";
    }
    return 0;
}
