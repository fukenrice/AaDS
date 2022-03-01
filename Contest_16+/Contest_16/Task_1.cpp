#include <iostream>
#include <vector>
#include <algorithm>

bool isHeap(int *heap, int index, int size) {
    if (size <= 2 * index + 2 && size <= 2 * index + 1) {
        return true;
    }
    if ((size <= 2 * index + 1 ||
         heap[index] >= heap[2 * index + 1] && isHeap(heap, 2 * index + 1, size)) &&
        (size <= 2 * index + 2 ||
         heap[index] >= heap[2 * index + 2] && isHeap(heap, 2 * index + 2, size))) {
        return true;
    }
    return false;
}

int main() {
    int num, element;
    std::cin >> num;
    int *heap = new int[num];
    for (int i = 0; i < num; ++i) {
        std::cin >> element;
        heap[i] = element;
    }
    int left = 0, right = num;
    int middle;
    while (right - left > 1) {
        middle = (right + left) / 2;
        if (isHeap(heap, 0, middle + 1)) {
            left = middle;
        } else {
            right = middle;
        }
    }
    std::cout << left;
    delete[] heap;
    return 0;
}
