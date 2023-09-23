#pragma once

#include <cassert>
#include <iostream>

template <typename T>
class DoublyLinkedList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };

    DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList& other)
    {
        Node* current = other.m_head;

        while (current != nullptr) {
            PushBack(current->data);
            current = current->next;
        }
    }

    DoublyLinkedList(DoublyLinkedList&& other) noexcept
        : m_head { other.m_head }
    {
        other.m_head = nullptr;
    }

    DoublyLinkedList& operator=(const DoublyLinkedList& rhs)
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

    DoublyLinkedList& operator=(DoublyLinkedList&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_head = rhs.m_head;

            rhs.m_head = nullptr;
        }
        return *this;
    }

    ~DoublyLinkedList()
    {
        Clear();
    }

    void PushFront(const T& data)
    {
        Node* newNode { new Node { data, nullptr, m_head } };
        m_head = newNode;
    }

    void PushBack(const T& data)
    {
        Node* newNode { new Node { data, nullptr, nullptr } };

        if (IsEmpty()) {
            m_head = newNode;
        } else {
            Node* current = m_head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
        }
    }

    void PopFront()
    {
        assert(!IsEmpty());

        Node* current = m_head;

        if (current->next) {
            current->next->prev = nullptr;
            m_head = current->next;
        }

        delete current;
    }

    void PopBack()
    {
        assert(!IsEmpty());

        Node* current = m_head;

        if (current->next == nullptr) {
            delete current;
            m_head = nullptr;
        } else {
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
        std::cout << "Print Doubly Linked List" << std::endl;

        if (IsEmpty()) {
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
    Node* m_head;
};