#include "binaryTree.h"

binaryTree::binaryTree() : m_root(nullptr), m_index(0), m_total(0) {};

binaryTree::binaryTree(Node* root, int index, int total) : m_root(root), m_index(index), m_total(total) {};

Node* binaryTree::getRoot(){
    return m_root;
}

void binaryTree::preorderTraversal(Node* node){
    if (node == nullptr){
        return;
    } 
    else{
        std::cout << *(node->getPair()) << std::endl;
        preorderTraversal(node->getLeft());
        preorderTraversal(node->getRight());
    }
}

void binaryTree::inorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    } else {
        inorderTraversal(node->getLeft());
        std::cout << *(node->getPair()) << ": " << node->getPair()->getCounter() << std::endl;
        inorderTraversal(node->getRight());
    }
}

void binaryTree::postorderTraversal(Node* node){
    if(node == nullptr){
        return;
    }
    else{
        postorderTraversal(node->getLeft());
        postorderTraversal(node->getRight());
        std::cout << *(node->getPair()) << std::endl;
    }
}

bool binaryTree::isEmpty(){
    return (m_root == nullptr);
}

searchResultBinary binaryTree::binarySearch(const Pair& pair) {
    Node* currentNode = m_root;
    Node* parentNode = nullptr;
    while (currentNode) {
        if (pair == *(currentNode->getPair())) { 
            return {currentNode, true};              // pair already in BST
        } 
        else if (pair < *(currentNode->getPair())) { // update current node to point to the left child
            parentNode = currentNode;                // and the parent node to point to the previous current node
            currentNode = currentNode->getLeft();
        } 
        else{                                        // same as above
            parentNode = currentNode;
            currentNode = currentNode->getRight();
        } 
    } 
    return {parentNode, false};   // return parentNode
}

bool binaryTree::insertPair(const Pair& pair) {
    if (isEmpty()) {
        m_root = new Node(pair);
        m_index = 1;
        m_total = 1;
        return true;
    } 
    else{
        searchResultBinary result = binarySearch(pair);
        if (result.found){  // pair already exists in the tree
            m_total++;     
            result.node->getPair()->updateCounter();
            return true; 
        } 
        else{               // pair is not in the tree
            Node* newNode = new Node(pair);
            if (pair < *(result.node->getPair())){
                result.node->setLeft(newNode);
                result.node->getPair()->setCounter(1);
            } 
            else{
                result.node->setRight(newNode);
                result.node->getPair()->setCounter(1);
            }
            m_total++;
            m_index++;
            return true;
        }
    }
    return false; // no space for inserting pair
}

int binaryTree::searchPair(const Pair& pair){
    if(isEmpty()){
        return 0;
    }
    else{
        searchResultBinary result = binarySearch(pair); 
        if(result.found) // pair is found in the tree
            return result.node->getPair()->getCounter();
        else{
            return 0;
        }
    }
}

int binaryTree::getDistinctPairCount(){ 
    return m_index;
}

int binaryTree::getTotalPairCount(){
    return m_total;
}
