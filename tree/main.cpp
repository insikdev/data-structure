#include "binary_search_tree.h"
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

    {
        BinarySearchTree<int, int> t;

        for (int num : { 5, 8, 2, 7, 4, 9 }) {
            t.Insert({ num, num });
        }

        t.InOrderRecursive();
        t.Remove(5);
        t.InOrderRecursive();
        t.InOrderRecursive();
    }

    { // test constructor

        BinarySearchTree<int, int> t;

        for (int num : { 5, 8, 2, 7, 4, 9 }) {
            t.Insert({ num, num });
        }

        BinarySearchTree<int, int> copy { t };

        t.InOrderRecursive();
        copy.InOrderRecursive();

        t.Remove(7);
        copy.Insert({ 10, 10 });
        t.InOrderRecursive();
        copy.InOrderRecursive();

        BinarySearchTree<int, int> copy2;
        copy2 = t;
        t.Remove(5);
        copy2.Insert({ 20, 20 });
        copy2.InOrderRecursive();

        BinarySearchTree<int, int> move { std::move(t) };
        move.InOrderRecursive();

        BinarySearchTree<int, int> move2;
        move2 = std::move(move);

        move2.InOrderRecursive();
    }

    return 0;
}