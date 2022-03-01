#include <iostream>

void merge(int *arr, int first, int last) {
    int *res, start, middle, final;
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    res = new int[last - first + 1];
    for (int i = first; i <= last; ++i) {
        if ((start <= middle) && (final > last || arr[start] < arr[final])) {
            res[i - first] = arr[start++];
        } else {
            res[i - first] = arr[final++];
        }
    }
    for (int i = first; i <= last; ++i) {
        arr[i] = res[i - first];
    }
    delete[] res;
}

void mergeSort(int *arr, int first, int last) {
    if (first < last) {
        mergeSort(arr, first, (first + last) / 2);
        mergeSort(arr, (first + last) / 2 + 1, last);
        merge(arr, first, last);
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
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
}
