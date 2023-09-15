#pragma once

#include <cassert>
#include <iostream>

template <typename T>
class SinglyLinkedList {
public:
    struct Node {
        T data;
        Node* next;
    };

    SinglyLinkedList() = default;

    SinglyLinkedList(const SinglyLinkedList& other)
    {
        Node* current = other.m_head;

        while (current != nullptr) {
            PushBack(current->data);
            current = current->next;
        }
    }

    SinglyLinkedList(SinglyLinkedList&& other) noexcept
        : m_head { other.m_head }
    {
        other.m_head = nullptr;
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& rhs)
    {
        if (this != &rhs) {
            Clear();
            Node* current = rhs.m_head;

            while (current != nullptr) {
                PushBack(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    SinglyLinkedList& operator=(SinglyLinkedList&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_head = rhs.m_head;

            rhs.m_head = nullptr;
        }
        return *this;
    }

    ~SinglyLinkedList()
    {
        Clear();
    }

    void PushFront(const T& data)
    {
        Node* newNode { new Node { data, m_head } };
        m_head = newNode;
    }

    void PushBack(const T& data)
    {
        Node* newNode { new Node { data, nullptr } };

        if (IsEmpty()) {
            m_head = newNode;
        } else {
            Node* current = m_head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }
    }

    void PopFront()
    {
        assert(!IsEmpty());

        Node* current = m_head;
        m_head = current->next;
        delete current;
    }

    void PopBack()
    {
        assert(!IsEmpty());

        if (m_head->next == nullptr) {
            delete m_head;
            m_head = nullptr;
        } else {
            Node* current = m_head;

            while (current->next->next != nullptr) {
                current = current->next;
            }

            delete current->next;
            current->next = nullptr;
        }
    }

    void Clear()
    {
        Node* current = m_head;

        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }

        m_head = nullptr;
    }

    const T& Front() const
    {
        assert(!IsEmpty());

        return m_head->data;
    }

    const T& Back() const
    {
        assert(!IsEmpty());

        Node* current = m_head;

        while (current->next != nullptr) {
            current = current->next;
        }

        return current->data;
    }

    bool IsEmpty() const
    {
        return m_head == nullptr;
    }

    size_t Size() const
    {
        int count = 0;
        Node* current = m_head;

        while (current != nullptr) {
            current = current->next;
            count++;
        }

        return count;
    }

    void Print() const
    {
        std::cout << "Print Singly Linked List" << std::endl;

        if (Size() == 0) {
            std::cout << "empty";
        } else {
            Node* current = m_head;

            while (current != nullptr) {
                std::cout << current->data << " ";
                current = current->next;
            }
        }

        std::cout << std::endl;
    }

private:
    Node* m_head {};
};
