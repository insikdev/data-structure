#include "deque.h"
#include "queue.h"

int main()
{
    {
        Queue<int> q { 2 };
        q.Push(0);
        q.Push(1);
        q.Push(2);
        q.Push(3);
        q.Pop();
        q.Pop();
        q.Push(4);
        q.Print();
    }

    {
        Deque<int> d;
        d.PopBack();

        d.PushFront(0);
        d.PushFront(1);
        d.PushFront(2);
        d.PopBack();
        d.Print();
    }

    return 0;
}