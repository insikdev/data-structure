#include "max_heap.h"

int main()
{
    {
        MaxHeap<int> h;
        for (int i : { 2, 8, 5, 3, 2, 1, 9, 3, 7 }) {
            h.Push(i);
        }

        h.Print();
        h.Pop();
        h.Print();
    }
    return 0;
}