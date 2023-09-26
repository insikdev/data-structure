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

    { // Josephus Problem
        int n = 7;
        int k = 3;
        Queue<int> q;

        for (int i = 1; i <= n; i++) {
            q.Push(i);
        }

        while (q.Size() != 1) {
            for (int i = 0; i < k - 1; i++) {
                int temp = q.Front();
                q.Pop();
                q.Push(temp);
            }

            std::cout << "Executed: " << q.Front() << std::endl;
            q.Pop();
        }

        std::cout << "Survivor: " << q.Front() << std::endl;
    }

    {
        Deque<int> d;
        d.PushFront(0);
        d.PushFront(1);
        d.PushFront(2);
        d.PopBack();
        d.Print();
    }

    return 0;
}