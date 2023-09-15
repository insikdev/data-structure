#include "singly_linked_list.h"
#include <utility>

int main()
{
    {
        SinglyLinkedList<int> s;

        s.Print();
        s.PushBack(0);
        s.PushBack(1);
        s.PushBack(2);
        s.PushFront(3);
        s.PushFront(4);
        s.PopBack();
        s.PopFront();

        s.Print();
    }

    return 0;
}