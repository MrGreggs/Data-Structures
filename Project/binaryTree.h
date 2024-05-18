#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Pair.h"
#include "Node.h"

struct searchResultBinary{
    Node* node;
    bool found;
};

class binaryTree{
    public:
        binaryTree();
        binaryTree(Node* root, int index, int total);
        Node* getRoot();  // return the root of the tree
        void preorderTraversal(Node* node);
        void inorderTraversal(Node* node);
        void postorderTraversal(Node* node);
        int getDistinctPairCount(); // return number of distinct pairs
        int getTotalPairCount(); // return total amount of pairs
        bool isEmpty();
        bool insertPair(const Pair& pair);
        int searchPair(const Pair& pair);  // search pair and return its counter
        searchResultBinary binarySearch(const Pair& pair);

    private:
        Node* m_root;
        int m_index = 0; // number of distinct pairs
        int m_total = 0; // number of total pairs
};
#endif