#include <utility>

void SelectionSort(int* arr, size_t n)
{
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        std::swap(arr[i], arr[minIndex]);
    }
}