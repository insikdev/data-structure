#include "sort.h"

int main()
{
    { // bubble sort
        int arr[] { 5, 8, 2, 6, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        BubbleSort(arr, n);
        PrintArray(arr, n);
    }

    { // selection sort
        int arr[] { 5, 8, 2, 6, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        SelectionSort(arr, n);
        PrintArray(arr, n);
    }

    { // insertion sort
        int arr[] { 5, 8, 2, 6, 1 };
        int n = sizeof(arr) / sizeof(arr[0]);

        InsertionSort(arr, n);
        PrintArray(arr, n);
    }

    return 0;
}
