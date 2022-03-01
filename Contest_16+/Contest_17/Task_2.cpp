#include <iostream>
#include <utility>

void quickSort(int *arr, int first_index, int last_index, int *calls) {
    *calls += 1;
    int middle = arr[(first_index + last_index) / 2];
    int low = first_index, high = last_index;
    do {
        // Поставить нестрогое.
        while (arr[low] < middle) {
            low++;
        }
        while (arr[high] > middle) {
            high--;
        }
        if (low <= high) {
            std::swap(arr[low++], arr[high--]);
        }
    } while (low <= high);
    if (high > first_index) {
        quickSort(arr, first_index, high, calls);
    }
    if (low < last_index) {
        quickSort(arr, low, last_index, calls);
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
    std::cout << calls << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}
