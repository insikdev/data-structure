#include "stack.h"

int main(void)
{
    {
        Stack<int> s;

        s.Push(0);
        s.Push(1);
        s.Push(2);
        s.Push(3);
        s.Push(4);
        s.Pop();
        s.Print();
    }

    { // reverse string
        Stack<char> s;

        s.Push('H');
        s.Push('e');
        s.Push('l');
        s.Push('l');
        s.Push('o');

        while (!s.IsEmpty()) {
            std::cout << s.Top();
            s.Pop();
        }
    }

    return 0;
}