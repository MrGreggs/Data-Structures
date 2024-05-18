#include "AVL.h"

AVL::AVL() : m_root(nullptr), m_index(0), m_total(0) {};

AVL::AVL(Node* root, int index, int total) : m_root(root), m_index(index), m_total(total) {};

Node* AVL::getRoot(){
    return m_root;
}

void AVL::preorderTraversal(Node* node){
    if(node == nullptr)
        return;
    else{
    std::cout << *(node->getPair()) << std::endl;
    preorderTraversal(node->getLeft());
    preorderTraversal(node->getRight());
    }
}

void AVL::inorderTraversal(Node* node){
    if(node == nullptr)
        return;
    else{
    inorderTraversal(node->getLeft());
    std::cout << *(node->getPair()) << ": " << node->getPair()->getCounter() << std::endl;
    inorderTraversal(node->getRight());
    }
}

void AVL::postorderTraversal(Node* node){
    if(node == nullptr)
        return;
    else{
        postorderTraversal(node->getLeft());
        postorderTraversal(node->getRight());
        std::cout << *(node->getPair()) << std::endl;
    }
}

bool AVL::isEmpty(){
    return (m_root == nullptr);
}

void AVL::deleteTree(Node* node){
    if (isEmpty()){
        return;
    }
    deleteTree(node->getLeft());
    deleteTree(node->getRight());
    delete node;
    
    m_root = nullptr;
    m_index = 0;
    m_total = 0;
}

searchResultAVL AVL::binarySearch(const Pair& pair){
    Node* currentNode = m_root;      // assign currentNode value equal to m_root                                
    Node* parentNode = nullptr;      // and parentNode to null, since root has no parent
    while(currentNode != nullptr){   // then iteratevely find the node with the same value as the pair
        if(pair == *(currentNode->getPair())){
            return {currentNode, true};        // pair already in AVL tree
        }
        else if(pair > *(currentNode->getPair())){ // search right subtree
            parentNode = currentNode;
            currentNode = currentNode->getRight();
        }
        else if(pair < *(currentNode->getPair())){ // search left subtree 
            parentNode = currentNode;
            currentNode = currentNode->getLeft();
        }
    }
    currentNode = parentNode;
    return {currentNode, false};     // pair not in AVL tree
}

bool AVL::insertPair(const Pair& pair){
    if(isEmpty()){ // tree is empty, thus add pair as root of tree
        m_root = new Node(pair);
        m_root->getPair()->setCounter(1);
        m_index = 1;
        m_total = 1;
    }
    else{
        searchResultAVL result = binarySearch(pair);
        if(result.m_found){ // if pair is found, update counters
            m_total++;
            (*result.m_currentNode->getPair()).updateCounter();
            return true;
        }
        else{  // create new node on the left or right of the result.m_currentNode, then update counters
            Node* newNode = new Node(pair);
            if (pair < *(result.m_currentNode->getPair())){
                result.m_currentNode->setLeft(newNode);
                newNode->setParent(result.m_currentNode);
                newNode->getPair()->setCounter(1);
            } 
            else{
                result.m_currentNode->setRight(newNode);
                newNode->setParent(result.m_currentNode);
                newNode->getPair()->setCounter(1);
            }
            m_index++;
            m_total++;
            updateNodeHeight(newNode);
            return true;
        }
    }
    return false;
}

int AVL::getHeight(Node* node){
    // int height = 0;
    if(node == nullptr){
        return 0;
    }
    // recursively search for the max of the two subtrees
    return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

int AVL::getBalance(Node* node){ // calculate the balance of the node
    if (node != nullptr){       // by comparing the left and right subtree height
        int leftHeight = getHeight(node->getLeft());
        int rightHeight = getHeight(node->getRight());
        int balance = leftHeight - rightHeight;
        return balance;
    }
    return 0; 
}

void AVL::updateNodeHeight(Node* node){ // based on the balance of a node and its child's balance, perform rotations
    int balance = getBalance(node);
    if(balance > 1){
        if(getBalance(node->getLeft()) > 0){ // node balance 2, left child balance 1
            node = leftRotate(node);
        }
        else{
            node = leftRightRotate(node);    // node balance 2, right child balance -1
        }
    }
    else if(getBalance(node) < - 1){         // node balance -2, right child balance -1
        if(getBalance(node->getRight()) < 0){
            node = rightRotate(node);
        }
        else{
            node = rightLeftRotate(node);   // node balance -2, left child balance 1
        }
    }
}

int AVL::searchPair(const Pair& pair){
    searchResultAVL result = binarySearch(pair);
    if(result.m_found)
        return result.m_currentNode->getPair()->getCounter();
    return 0;
}

// ROTATIONS

Node* AVL::leftRotate(Node* node){
    Node* newNode = node->getLeft();
    node->setLeft(newNode->getRight());
    newNode->setRight(node);
    return newNode;
}

Node* AVL::rightRotate(Node* node){
    Node* newNode = node->getRight();
    node->setRight(newNode->getLeft());
    newNode->setLeft(node);
    return newNode;
}

Node* AVL::rightLeftRotate(Node* node){
    Node* newNode = node->getRight();
    node->setRight(leftRotate(newNode));
    return rightRotate(node);    
}

Node* AVL::leftRightRotate(Node* node){
   Node* newNode = node->getLeft();
   node->setLeft(rightRotate(newNode));
   return leftRotate(node);
}

int AVL::getDistinctPairCount(){
    return m_index;
}

int AVL::getTotalPairCount(){
    return m_total;
}