#include "doubly_linked_list.h"
#include "singly_linked_list.h"

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

    {
        DoublyLinkedList<int> d;

        d.Print();
        d.PushBack(0);
        d.PushBack(1);
        d.PushBack(2);
        d.PushFront(3);
        d.PushFront(4);
        d.PopBack();
        d.PopFront();

        d.Print();
    }

    return 0;
}