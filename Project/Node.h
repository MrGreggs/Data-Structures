#ifndef NODE_H
#define NODE_H
#include "Pair.h"


class Node{
    public:
        Node(const Pair& pair);
        Pair* getPair();   // return pair
        Node* getParent(); // return node pointer to parent
        Node* getLeft();  // return node pointer to left child
        Node* getRight(); // return node pointer to right child
        void setPair(Pair pair);
        void setParent(Node* parent);
        void setLeft(Node* pair);
        void setRight(Node* pair);
        void setBalance(int balance);
    private:
        Pair* m_pair;
        Node* m_right;
        Node* m_left;
        Node* m_parent;
        int m_balance; // represents the difference between left subtree's height and right subtree's height
};
#endif