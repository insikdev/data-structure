#pragma once

#include <iostream>

template <typename K, typename V>
class BinarySearchTree {
public:
    struct Item {
        K key;
        V value;
    };
    struct Node {
        Item item;
        Node* left;
        Node* right;
    };

    BinarySearchTree() = default;

    BinarySearchTree(const BinarySearchTree& other)
        : m_root { CopyRecursive(other.m_root) }
    {
    }

    BinarySearchTree(BinarySearchTree&& other) noexcept
        : m_root { other.m_root }
    {
        other.m_root = nullptr;
    }

    BinarySearchTree& operator=(const BinarySearchTree& rhs)
    {
        if (this != &rhs) {
            Clear();
            m_root = CopyRecursive(rhs.m_root);
        }

        return *this;
    }

    BinarySearchTree& operator=(BinarySearchTree&& rhs) noexcept
    {
        if (this != &rhs) {
            Clear();
            m_root = rhs.m_root;
            rhs.m_root = nullptr;
        }

        return *this;
    }

    ~BinarySearchTree()
    {
        Clear();
    }

    void Insert(const Item& item)
    {
        m_root = InsertRecursive(m_root, item);
    }

    void Remove(const K& key)
    {
        m_root = RemoveRecursive(m_root, key);
    }

    Node* Search(const K& key) const
    {
        return SearchRecursive(m_root, key);
    }

    void InOrderRecursive() const
    {
        std::cout << "in order traversal using recursion" << std::endl;
        InOrderRecursiveHelper(m_root);
        std::cout << std::endl;
    }

    void Clear()
    {
        m_root = ClearRecursive(m_root);
    }

private:
    Node* m_root {};

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
        std::cout << node->item.key << " ";
    }

    void InOrderRecursiveHelper(Node* node) const
    {
        if (node) {
            InOrderRecursiveHelper(node->left);
            Visit(node);
            InOrderRecursiveHelper(node->right);
        }
    }

    Node* InsertRecursive(Node* node, const Item& item)
    {
        if (!node) {
            return new Node { item, nullptr, nullptr };
        }

        if (item.key < node->item.key) {
            node->left = InsertRecursive(node->left, item);
        } else if (item.key > node->item.key) {
            node->right = InsertRecursive(node->right, item);
        } else {
            node->item = item;
        }

        return node;
    }

    Node* RemoveRecursive(Node* node, const K& key)
    {
        if (!node) {
            return nullptr;
        }

        if (key < node->item.key) {
            node->left = RemoveRecursive(node->left, key);
        } else if (key > node->item.key) {
            node->right = RemoveRecursive(node->right, key);
        } else {
            if (!node->left) {
                Node* child = node->right;
                delete node;
                return child;
            }

            if (!node->right) {
                Node* child = node->left;
                delete node;
                return child;
            }

            Node* succesor = GetSuccessor(node->right);
            node->item = succesor->item;
            node->right = RemoveRecursive(node->right, succesor->item.key);
        }

        return node;
    }

    Node* SearchRecursive(Node* node, const K& key)
    {
        if (!node) {
            return nullptr;
        }

        if (key < node->item.key) {
            return SearchRecursive(node->left, key);
        }

        if (key > node->item.key) {
            return SearchRecursive(node->right, key);
        }

        return node;
    }

    Node* GetSuccessor(Node* node) const
    {
        Node* current = node;
        while (current->left) {
            current = current->left;
        }

        return current;
    }
};