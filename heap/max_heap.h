#pragma once

#include <cassert>
#include <iostream>

template <typename T>
class MaxHeap {
public:
    MaxHeap(size_t capacity = 5)
        : m_capacity { capacity }
        , m_data { new T[capacity + 1] }
    {
    }

    MaxHeap(const MaxHeap& other)
        : m_capacity { other.m_capacity }
        , m_size { other.m_size }
    {
        m_data = new T[m_capacity + 1];
        memcpy(m_data, other.m_data, sizeof(T) * (m_size + 1));
    }

    MaxHeap(MaxHeap&& other) noexcept
        : m_data { other.m_data }
        , m_capacity { other.m_capacity }
        , m_size { other.m_size }
    {
        other.m_data = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }

    MaxHeap& operator=(const MaxHeap& rhs)
    {
        if (this != &rhs) {
            Clear();
            m_capacity = rhs.m_capacity;
            m_size = rhs.m_size;
            m_data = new T[m_capacity + 1];

            memcpy(m_data, rhs.m_data, sizeof(T) * (m_size + 1));
        }
        return *this;
    }

    MaxHeap& operator=(MaxHeap&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_capacity = rhs.m_capacity;
            m_size = rhs.m_size;
            m_data = rhs.m_data;

            rhs.m_capacity = 0;
            rhs.m_size = 0;
            rhs.m_data = nullptr;
        }

        return *this;
    }

    ~MaxHeap()
    {
        Clear();
    }

    void Push(const T& data)
    {
        if (m_size == m_capacity) {
            ExpandCapacity();
        }

        m_size++;

        int current = m_size;

        while (current != 1) {
            if (m_data[current / 2] >= data) {
                break;
            }

            m_data[current] = m_data[current / 2];
            current /= 2;
        }

        m_data[current] = data;
    }

    void Pop()
    {
        assert(!IsEmpty());

        T last = m_data[m_size];
        m_size--;

        size_t current = 1;
        size_t child = 2;

        while (child <= m_size) {
            if (child + 1 <= m_size && m_data[child] < m_data[child + 1]) {
                child++;
            }

            if (last >= m_data[child]) {
                break;
            }

            m_data[current] = m_data[child];
            current = child;
            child *= 2;
        }

        m_data[current] = last;
    }

    const T& Top() const
    {
        assert(!IsEmpty());

        return m_data[1];
    }

    size_t Size() const
    {
        return m_size;
    }

    bool IsEmpty() const
    {
        return m_size == 0;
    }

    void Print() const
    {
        std::cout << "Print Max Heap" << std::endl;

        if (IsEmpty()) {
            std::cout << "empty";
        } else {
            for (int i = 1; i <= m_size; i++) {
                std::cout << m_data[i] << ' ';
            }
        }

        std::cout << std::endl;
    }

private:
    T* m_data;
    size_t m_capacity;
    size_t m_size { 0 };

private:
    void ExpandCapacity()
    {
        T* expand = new T[m_capacity * 2 + 1];
        memcpy(expand, m_data, sizeof(T) * (m_size + 1));
        delete[] m_data;

        m_data = expand;
        m_capacity *= 2;
    }

    void Clear()
    {
        delete[] m_data;
        m_size = 0;
        m_capacity = 0;
    }
};