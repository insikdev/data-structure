#pragma once

#include <cassert>
#include <iostream>

template <typename T>
class Stack {
public:
    Stack(int capacity = 5)
        : m_capacity { capacity }
        , m_data { new T[capacity] }
    {
    }

    Stack(const Stack& other)
        : m_capacity { other.m_capacity }
        , m_top { other.m_top }
    {
        m_data = new T[m_capacity];
        memcpy(m_data, other.m_data, sizeof(T) * (m_top + 1));
    }

    Stack(Stack&& other) noexcept
        : m_data { other.m_data }
        , m_capacity { other.m_capacity }
        , m_top { other.m_top }
    {
        other.m_data = nullptr;
        other.m_top = -1;
        other.m_capacity = 0;
    }

    Stack& operator=(const Stack& rhs)
    {
        if (this != &rhs) {
            Clear();
            m_capacity = rhs.m_capacity;
            m_top = rhs.m_top;
            m_data = new T[m_capacity];
            memcpy(m_data, rhs.m_data, sizeof(T) * (m_top + 1));
        }

        return *this;
    }

    Stack& operator=(Stack&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_data = rhs.m_data;
            m_top = rhs.m_top;
            m_capacity = rhs.m_capacity;

            rhs.m_data = nullptr;
            rhs.m_top = -1;
            rhs.m_capacity = 0;
        }

        return *this;
    }

    ~Stack()
    {
        Clear();
    }

    void Push(const T& data)
    {
        if (IsFull()) {
            ExpandCapacity();
        }

        m_data[++m_top] = data;
    }

    void Pop()
    {
        assert(!IsEmpty());

        m_top--;
    }

    const T& Top() const
    {
        assert(!IsEmpty());

        return m_data[m_top];
    }

    size_t Size() const
    {
        return m_top + 1;
    }

    bool IsEmpty() const
    {
        return m_top == -1;
    }

    void Print() const
    {
        std::cout << "Print Stack" << std::endl;

        if (Size() == 0) {
            std::cout << "empty";
        } else {
            for (int i = 0; i <= m_top; i++) {
                std::cout << m_data[i] << ' ';
            }
        }

        std::cout << std::endl;
    }

private:
    T* m_data;
    int m_top { -1 };
    int m_capacity;

private:
    bool IsFull()
    {
        return m_capacity - 1 == m_top;
    }

    void ExpandCapacity()
    {
        T* expand = new T[m_capacity * 2];
        memcpy(expand, m_data, sizeof(T) * Size());
        delete[] m_data;

        m_data = expand;
        m_capacity *= 2;
    }

    void Clear()
    {
        delete[] m_data;
        m_top = -1;
        m_capacity = 0;
    }
};
