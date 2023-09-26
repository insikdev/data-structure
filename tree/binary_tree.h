#pragma once

#include "queue/queue.h"
#include "stack/stack.h"
#include <iostream>

template <typename T>
class BinaryTree {
public:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    BinaryTree(Node* root)
        : m_root { root }
    {
    }

    BinaryTree(const BinaryTree& other)
        : m_root { CopyRecursive(other.m_root) }
    {
    }

    BinaryTree(BinaryTree&& other) noexcept
        : m_root { other.m_root }
    {
        other.m_root = nullptr;
    }

    BinaryTree& operator=(const BinaryTree& rhs)
    {
        if (this != &rhs) {
            Clear();
            m_root = CopyRecursive(rhs.m_root);
        }
        return *this;
    }

    BinaryTree& operator=(BinaryTree&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_root = rhs.m_root;
            rhs.m_root = nullptr;
        }
        return *this;
    }

    ~BinaryTree()
    {
        Clear();
    }

    void PreOrderRecursive() const
    {
        std::cout << "pre order traversal using recursion" << std::endl;
        PreOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void InOrderRecursive() const
    {
        std::cout << "in order traversal using recursion" << std::endl;
        InOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void PostOrderRecursive() const
    {
        std::cout << "post order traversal using recursion" << std::endl;
        PostOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void LevelOrder() const
    {
        std::cout << "level order traversal" << std::endl;

        Queue<Node*> q;
        q.Push(m_root);

        while (!q.IsEmpty()) {
            Node* current = q.Front();
            Visit(current);
            q.Pop();

            if (current->left) {
                q.Push(current->left);
            }
            if (current->right) {
                q.Push(current->right);
            }
        }

        std::cout << std::endl;
    }

    void PreOrder() const
    {
        std::cout << "pre order traversal" << std::endl;

        Stack<Node*> s;
        s.Push(m_root);

        while (!s.IsEmpty()) {
            Node* current = s.Top();

            s.Pop();
            Visit(current);

            if (current->right) {
                s.Push(current->right);
            }
            if (current->left) {
                s.Push(current->left);
            }
        }

        std::cout << std::endl;
    }

    void InOrder() const
    {
        std::cout << "in order traversal" << std::endl;

        Stack<Node*> s;

        Node* current = m_root;

        while (!s.IsEmpty() || (current != nullptr)) {
            while (current != nullptr) {
                s.Push(current);
                current = current->left;
            }

            current = s.Top();
            s.Pop();
            Visit(current);
            current = current->right;
        }

        std::cout << std::endl;
    }

    void Clear()
    {
        m_root = ClearRecursive(m_root);
    }

private:
    Node* m_root;

private:
    Node* CopyRecursive(Node* node)
    {
        if (!node) {
            return nullptr;
        }

        Node* newNode { new Node { node->item, nullptr, nullptr } };
        newNode->left = CopyRecursive(node->left);
        newNode->right = CopyRecursive(node->right);

        return newNode;
    }

    Node* ClearRecursive(Node* node)
    {
        if (node) {
            ClearRecursive(node->left);
            ClearRecursive(node->right);
            delete node;
        }

        return nullptr;
    }

    void Visit(Node* node) const
    {
        std::cout << node->data << " ";
    }

    void PreOrderRecursiveHelper(Node* node) const
    {
        if (node) {
            Visit(node);
            PreOrderRecursiveHelper(node->left);
            PreOrderRecursiveHelper(node->right);
        }
    }

    void InOrderRecursiveHelper(Node* node) const
    {
        if (node) {
            InOrderRecursiveHelper(node->left);
            Visit(node);
            InOrderRecursiveHelper(node->right);
        }
    }

    void PostOrderRecursiveHelper(Node* node) const
    {
        if (node) {
            PostOrderRecursiveHelper(node->left);
            PostOrderRecursiveHelper(node->right);
            Visit(node);
        }
    }
};
