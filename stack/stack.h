#ifndef STACK_H
#define STACK_H

#include "cassert"
#include "cstring"
#include "iostream"

template <typename T>
class Stack {

public:
    Stack(int capacity = 5)
        : m_capacity { capacity }
        , m_data { new T[capacity] } {};

    Stack(const Stack& other)
        : m_capacity { other.m_capacity }
        , m_top { other.m_top }
    {
        m_data = new T[m_capacity];
        memcpy(m_data, other.m_data, sizeof(T) * (m_top + 1));
    }

    ~Stack()
    {
        if (m_data) {
            delete[] m_data;
        }
    }

    void Pop()
    {
        assert(!IsEmpty());

        m_top--;
    };

    void Push(const T& data)
    {
        if (m_capacity - 1 == m_top) {
            T* expand = new T[m_capacity * 2];
            memcpy(expand, m_data, sizeof(T) * Size());
            delete[] m_data;

            m_data = expand;
            m_capacity *= 2;
        }

        m_data[++m_top] = data;
    };

    T& Top()
    {
        assert(!IsEmpty());

        return m_data[m_top];
    }

    bool IsEmpty()
    {
        return m_top == -1;
    };

    int Size()
    {
        return m_top + 1;
    }

    void Print()
    {
        std::cout << "Print Stack" << std::endl;

        for (int i = 0; i <= m_top; i++) {
            std::cout << m_data[i] << ' ';
        }

        std::cout << std::endl;
    }

private:
    T* m_data = nullptr;
    int m_top = -1;
    int m_capacity = 0;
};

#endif /* STACK_H*/
