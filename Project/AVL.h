#ifndef AVL_H
#define AVL_H
#include "Pair.h"
#include "Node.h"

struct searchResultAVL{
    Node* m_currentNode;
    bool m_found;
};

class AVL{
    public:
        AVL();
        AVL(Node* root, int index, int total);
        Node* getRoot();
        void deleteTree(Node* root);
        void preorderTraversal(Node* node);
        void inorderTraversal(Node* node);
        void postorderTraversal(Node* node);
        int getDistinctPairCount(); // returns number of distinct pairs
        int getTotalPairCount(); // return total amount of pairs
        bool isEmpty();
        bool insertPair(const Pair& pair);
        int searchPair(const Pair& pair); // search pair and return its counter
        int getBalance(Node* node);
        int getHeight(Node* node);
        searchResultAVL binarySearch(const Pair& pair);
        void updateNodeHeight(Node* node);
        Node* leftRotate(Node* node);
        Node* rightRotate(Node* node);
        Node* rightLeftRotate(Node* node);
        Node* leftRightRotate(Node* node);
    private:
        Node* m_root;
        int m_index;
        int m_total;
};
#endif