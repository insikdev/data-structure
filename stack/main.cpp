#include "stack.h"

int main(void)
{
    {
        Stack<int> s;

        for (int i : { 0, 1, 2, 3, 4 }) {
            s.Push(i);
        }

        s.Pop();
        s.Print();
    }

    { // reverse string
        Stack<char> s;

        for (char i : "Hello") {
            s.Push(i);
        }

        while (!s.IsEmpty()) {
            std::cout << s.Top();
            s.Pop();
        }
    }

    return 0;
}