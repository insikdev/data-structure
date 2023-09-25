#include <iostream>
#include <string>

int SumRecursive(int* arr, size_t n, size_t i = 0)
{
    if (n == i)
        return 0;
    return arr[i] + SumRecursive(arr, n, i + 1);
};

size_t FactorialRecursive(size_t n)
{
    if (n == 1) {
        return 1;
    }

    return n * FactorialRecursive(n - 1);
}

size_t FibonacciRecursive(size_t n)
{
    if (n <= 1) {
        return n;
    }

    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

std::string ReverseStringRecursive(std::string str)
{
    if (str.empty()) {
        return "";
    }

    return ReverseStringRecursive(str.substr(1)) + str.front();
}

int BinarySearchRecursive(int* arr, int x, int left, int right)
{
    if (left > right) {
        return -1;
    }

    int middle = (left + right) / 2;

    if (arr[middle] == x) {
        return middle;
    }

    if (arr[middle] > x) {
        return BinarySearchRecursive(arr, x, left, middle - 1);
    }

    if (arr[middle] < x) {
        return BinarySearchRecursive(arr, x, middle + 1, right);
    }
}

void PermutationRecursive(std::string str, size_t left, size_t right)
{
    if (left == right) {
        for (char c : str) {
            std::cout << c;
        }
        std::cout << std::endl;
        return;
    }

    for (int i = left; i <= right; i++) {
        std::swap(str[i], str[left]);
        PermutationRecursive(str, left + 1, right);
        std::swap(str[i], str[left]);
    }
}

// 1. n-1개의 원판을 1번 -> 2번으로 이동
// 2. 1개의 원판을 1번 -> 3번으로 이동
// 3. n-1개의 원판을 2번 -> 3번으로 이동
void HanoiRecursive(int n, int from, int to, int aux)
{
    if (n == 0) {
        return;
    }

    HanoiRecursive(n - 1, from, aux, to);

    std::cout << "Move disk " << n << " from rod " << from << " to rod " << to << std::endl;

    HanoiRecursive(n - 1, aux, to, from);
}

int main()
{
    {
        int arr[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        std::cout << SumRecursive(arr, sizeof(arr) / sizeof(arr[0])) << std::endl;
    }

    {
        std::cout << FactorialRecursive(5) << std::endl;
    }

    {
        std::cout << FibonacciRecursive(10) << std::endl;
    }

    {
        int arr[] { 1, 3, 5, 7, 9, 11, 13 };
        std::cout << BinarySearchRecursive(arr, 11, 0, sizeof(arr) / sizeof(arr[0]) - 1) << std::endl;
    }

    {
        std::string str { "ABC" };
        PermutationRecursive(str, 0, str.size() - 1);
    }

    {
        std::string str { "Hello World!" };
        std::cout << ReverseStringRecursive(str) << std::endl;
    }

    {
        HanoiRecursive(1, 1, 3, 2);
    }

    return 0;
}
