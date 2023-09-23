#include "binary_tree.h"

int main()
{
    {
        using Node = BinaryTree<int>::Node;
        Node* n30 { new Node { 1, nullptr, nullptr } };
        Node* n31 { new Node { 3, nullptr, nullptr } };
        Node* n32 { new Node { 10, nullptr, nullptr } };
        Node* n20 { new Node { 2, n30, n31 } };
        Node* n21 { new Node { 5, nullptr, nullptr } };
        Node* n22 { new Node { 7, nullptr, nullptr } };
        Node* n23 { new Node { 9, nullptr, n32 } };
        Node* n10 { new Node { 4, n20, n21 } };
        Node* n11 { new Node { 8, n22, n23 } };
        Node* n0 { new Node { 6, n10, n11 } };

        BinaryTree<int> b { n0 };

        b.PreOrderRecursive();
        b.InOrderRecursive();
        b.PostOrderRecursive();
        b.LevelOrder();
        b.PreOrder();
        b.InOrder();
    }

    return 0;
}