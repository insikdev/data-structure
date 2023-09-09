#ifndef DEQUE_H
#define DEQUE_H

#include <cassert>
#include <iostream>

template <typename T>
class Deque {
public:
    Deque(int capacity = 5)
        : m_capacity { capacity }
        , m_front { 0 }
        , m_rear { 0 }
        , m_data { new T[capacity] }
    {
    }

    Deque(const Deque& other)
        : m_capacity { other.m_capacity }
        , m_front { other.m_front }
        , m_rear { other.m_rear }
    {
        m_data = new T[m_capacity];
        memcpy(m_data, other.m_data, sizeof(T) * m_capacity);
    }

    ~Deque()
    {
        if (m_data) {
            delete[] m_data;
        }
    }

    void PushFront(const T& data)
    {
        if (IsFull()) {
            ExpandCapacity();
        }

        m_data[m_front] = data;
        m_front = (m_front - 1 + m_capacity) % m_capacity;
    }

    void PushBack(const T& data)
    {
        if (IsFull()) {
            ExpandCapacity();
        }

        m_rear = (m_rear + 1) % m_capacity;
        m_data[m_rear] = data;
    }

    void PopFront()
    {
        assert(!IsEmpty());

        m_front = (m_front + 1) % m_capacity;
    }

    void PopBack()
    {
        assert(!IsEmpty());

        m_rear = (m_rear - 1 + m_capacity) % m_capacity;
    }

    T& Front()
    {
        assert(!IsEmpty());

        return m_data[(m_front + 1) % m_capacity];
    }

    T& Back()
    {
        assert(!IsEmpty());

        return m_data[m_rear];
    }

    int Size()
    {
        return (m_rear - m_front + m_capacity) % m_capacity;
    }

    bool IsEmpty()
    {
        return m_front == m_rear;
    }

    void Print()
    {
        std::cout << "Print Deque" << std::endl;

        for (int i = (m_front + 1) % m_capacity; i != (m_rear + 1) % m_capacity; i = (i + 1) % m_capacity) {
            std::cout << m_data[i] << ' ';
        }

        std::cout << std::endl;
    }

private:
    T* m_data;
    int m_front;
    int m_rear;
    int m_capacity;

    bool IsFull()
    {
        return ((m_rear + 1) % m_capacity) == m_front;
    }

    void ExpandCapacity()
    {
        T* expand = new T[m_capacity * 2];

        int count = 1;
        for (int i = (m_front + 1) % m_capacity; i != ((m_rear + 1) % m_capacity); i = (i + 1) % m_capacity) {
            expand[count++] = m_data[i];
        }

        m_front = 0;
        m_rear = m_capacity - 1;
        m_capacity *= 2;

        delete[] m_data;
        m_data = expand;
    }
};

#endif /* DEQUE_H */