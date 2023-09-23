#pragma once

#include <iostream>

void BubbleSort(int* arr, size_t n);

void SelectionSort(int* arr, size_t n);

void InsertionSort(int* arr, size_t n);

void PrintArray(int* arr, size_t n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}