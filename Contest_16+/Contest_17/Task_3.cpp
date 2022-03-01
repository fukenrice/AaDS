#include <iostream>
#include <utility>

int pivotList(int *arr, int first, int last) {
    int pivot = arr[last];
    int start = first - 1;
    for (int end = first; end <= last - 1; ++end) {
        if (arr[end] <= pivot) {
            std::swap(arr[++start], arr[end]);
        }
    }
    std::swap(arr[++start], arr[last]);
    return start;
}

void quickSort(int *arr, int first, int last, int *calls) {
    if (first < last) {
        *calls += 1;
        int pivot = pivotList(arr, first, last);
        quickSort(arr, first, pivot - 1, calls);
        quickSort(arr, pivot + 1, last, calls);
    }
}

int main() {
    int n, elem;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> elem;
        arr[i] = elem;
    }
    int calls = -1;
    quickSort(arr, 0, n - 1, &calls);
    if (n == 1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << calls << std::endl;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}
