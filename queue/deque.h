#pragma once

#include <cassert>
#include <iostream>

template <typename T>
class Deque {
public:
    Deque(int capacity = 5)
        : m_capacity { capacity }
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

    Deque(Deque&& other) noexcept
        : m_data { other.m_data }
        , m_front { other.m_front }
        , m_rear { other.m_rear }
        , m_capacity { other.m_capacity }
    {
        other.m_data = nullptr;
        other.m_front = 0;
        other.m_rear = 0;
        other.m_capacity = 0;
    }

    Deque& operator=(const Deque& rhs)
    {
        if (this != &rhs) {
            Clear();
            m_front = rhs.m_front;
            m_rear = rhs.m_rear;
            m_capacity = rhs.m_capacity;
            m_data = new T[m_capacity];

            memcpy(m_data, rhs.m_data, sizeof(T) * m_capacity);
        }
        return *this;
    }

    Deque& operator=(Deque&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_front = rhs.m_front;
            m_rear = rhs.m_rear;
            m_capacity = rhs.m_capacity;
            m_data = rhs.m_data;

            rhs.m_data = nullptr;
            rhs.m_front = 0;
            rhs.m_rear = 0;
            rhs.m_capacity = 0;
        }

        return *this;
    }

    ~Deque()
    {
        Clear();
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

    const T& Front() const
    {
        assert(!IsEmpty());

        return m_data[(m_front + 1) % m_capacity];
    }

    const T& Back() const
    {
        assert(!IsEmpty());

        return m_data[m_rear];
    }

    size_t Size() const
    {
        return (m_rear - m_front + m_capacity) % m_capacity;
    }

    bool IsEmpty() const
    {
        return m_front == m_rear;
    }

    void Print() const
    {
        std::cout << "Print Deque" << std::endl;

        if (Size() == 0) {
            std::cout << "empty";
        } else {
            for (int i = (m_front + 1) % m_capacity; i != (m_rear + 1) % m_capacity; i = (i + 1) % m_capacity) {
                std::cout << m_data[i] << ' ';
            }
        }

        std::cout << std::endl;
    }

private:
    T* m_data;
    int m_front { 0 };
    int m_rear { 0 };
    int m_capacity;

private:
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

    void Clear()
    {
        delete[] m_data;
        m_front = 0;
        m_rear = 0;
        m_capacity = 0;
    }
};
