#include <utility>

void BubbleSort(int* arr, size_t n)
{
    for (int i = 0; i < n - 1; i++) {
        bool isSorted = true;

        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }

        if (isSorted) {
            break;
        }
    }
}