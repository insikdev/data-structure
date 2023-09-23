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

    ~BinaryTree() { }

    void PreOrderRecursive()
    {
        std::cout << "pre order traversal using recursion" << std::endl;
        PreOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void InOrderRecursive()
    {
        std::cout << "in order traversal using recursion" << std::endl;
        InOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void PostOrderRecursive()
    {
        std::cout << "post order traversal using recursion" << std::endl;
        PostOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void LevelOrder()
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

    void PreOrder()
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

    void InOrder()
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

private:
    Node* m_root;

private:
    void Visit(Node* node)
    {
        std::cout << node->data << " ";
    }

    void PreOrderRecursiveHelper(Node* node)
    {
        if (node) {
            Visit(node);
            PreOrderRecursiveHelper(node->left);
            PreOrderRecursiveHelper(node->right);
        }
    }

    void InOrderRecursiveHelper(Node* node)
    {
        if (node) {
            InOrderRecursiveHelper(node->left);
            Visit(node);
            InOrderRecursiveHelper(node->right);
        }
    }

    void PostOrderRecursiveHelper(Node* node)
    {
        if (node) {
            PostOrderRecursiveHelper(node->left);
            PostOrderRecursiveHelper(node->right);
            Visit(node);
        }
    }
};
