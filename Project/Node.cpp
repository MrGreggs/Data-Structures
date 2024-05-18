#include "Node.h"

Node::Node(const Pair& pair){ // create a new node with m_pair = pair 
    m_pair = new Pair(pair); // and no children or parent
    m_parent = nullptr;
    m_left = nullptr;
    m_right = nullptr;
}

void Node::setPair(Pair pair){
    m_pair = new Pair(pair);
}

void Node::setParent(Node* parent){
    m_parent = parent;
}

void Node::setLeft(Node* pair){
    if (this != nullptr){
        m_left = pair;
    }
}

void Node::setRight(Node* pair){
    if (this != nullptr){
        m_right = pair;
    }
}

void Node::setBalance(int balance){
    if(this != nullptr){
        m_balance = balance;
    }
}

Pair* Node::getPair(){
    return m_pair;
}

Node* Node::getParent(){
    return m_parent;
}

Node* Node::getLeft(){
    if(this != nullptr){
        return m_left;
    }
    return nullptr; 
}

Node* Node::getRight(){
    if(this != nullptr){
        return m_right;
    }
    return nullptr; 
}

