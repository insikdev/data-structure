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

    return 0;
}