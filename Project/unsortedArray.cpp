#include "unsortedArray.h"

unsortedArray::unsortedArray(){
    m_size = 0;
}

unsortedArray::unsortedArray(unsigned long initialSize){ 
    m_size = initialSize;      
    m_data = new Pair[m_size];
    for(int i = 0; i < m_size; i++){
        m_data[i] = Pair();
    }
    m_index = 0;
    m_total = 0;
}

unsortedArray::~unsortedArray(){
    delete[] m_data;
}

void unsortedArray::insertPair(const Pair& p){
    if(m_index == m_size){
        resizeArray();
    }
    int pairIndex = checkPair(p); // linear search for pair
    if(pairIndex == -1){          // pair not in the array
        m_data[m_index] = p;      // assign the pair to the array
        m_data[m_index].setCounter(1); // set the counter of the inserted pair to 1
        m_index++;
        m_total++;
    } 
    else{ // pair already in the array
        m_data[pairIndex].updateCounter(); // update the counter of the existing pair
        m_total++;
    }
}

int unsortedArray::checkPair(const Pair& p){ // linear search
    for(int i = 0; i < m_index; i++){
        if (m_data[i] == p) // compare pairs and return the index if it is already in the array
            return i;
    }
    return -1; // pair not found in the array
}

int unsortedArray::searchPair(Pair p) {
    int pairIndex = checkPair(p);
    if (pairIndex >= 0) { // If pair is found, return its counter
        return m_data[pairIndex].getCounter();
    }
    return -1; // Pair not found in the array
}


void unsortedArray::resizeArray(){
        m_size *= 2; // double the size of the array
        Pair* newData = new Pair[m_size];
        for(int i = 0; i < m_index; i++) {
            newData[i] = m_data[i];  // copy existing pairs to new array
        }
        for(int i = m_index; i < m_size; i++){ // initialize remaining elements
            newData[i] = Pair();
        }
        delete[] m_data; // free memory from old array
        m_data = newData; // assign pointer of old data to new data
}

void unsortedArray::returnArray(){
    for (int i = 0; i < m_index; i++){
        std::cout << m_data[i] << ": " << m_data[i].getCounter() << std::endl;
    }
}

int unsortedArray::getSize(){
    return m_size; // return the total size of the array
}

int unsortedArray::getDistinctPairCount(){
    return m_index; // return the length of set of pairs
}

int unsortedArray::getTotalPairCount(){
    return m_total;
}