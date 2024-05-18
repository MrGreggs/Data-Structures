#include "sortedArray.h"

sortedArray::sortedArray(){
    m_size = 0; 
}

sortedArray::sortedArray(unsigned long initialSize){
    m_size = initialSize;
    m_data = new Pair[m_size];
    for(int i = 0; i < m_size; i++){
        m_data[i] = Pair();
    }
    m_index = 0;
    m_total = 0;
}

sortedArray::~sortedArray(){
        delete[] m_data;
}

searchResult sortedArray::binarySearch(const Pair& p){
    int left = 0, right = m_index - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(p == m_data[mid]){  // IF pair IS found
                return {mid, true}; // return position, true
            }
        else if (p < m_data[mid]) {
            right = mid - 1;  // ignore right half of array
        } 
        else {
            left = mid + 1;  // ignore left half of array
        }
    }
    return {left, false};  // IF left > right, return position, false since pair is not in the array
}

void sortedArray::insertPair(Pair p){
    if (m_index == m_size) {
        resizeArray();
    }
    searchResult result = binarySearch(p); 
    if(result.m_found){                            // IF binarySearch returns m_found == TRUE
        m_data[result.m_position].updateCounter(); // the pair is already in the array
        m_total++;                                 // and the counter and m_total are updated
        return;                  
    }                           

    else{ // if pair IS NOT found
        for (int i = m_index; i > result.m_position; i--){
            m_data[i] = m_data[i - 1];  // shift elements to the right
        }
        m_data[result.m_position] = p; // and place it in the m_position from binarySearch
        m_data[result.m_position].setCounter(1);
        m_index++;
        m_total++;
    }
}

int sortedArray::checkPair(Pair p){ // check for pair and return its position
    searchResult result = binarySearch(p);
    if(result.m_found)
        return result.m_position;
    else return -1;
}

int sortedArray::searchPair(const Pair& p){ // check for pair and return its counter
    searchResult result = binarySearch(p);
    if(result.m_found)
        return m_data[result.m_position].getCounter();
    else 
        return 0;
}

void sortedArray::resizeArray(){
    m_size *= 2; // double the size of the array
    Pair* newData = new Pair[m_size];
    for(int i = 0; i < m_index; i++)
    {
        newData[i] = m_data[i];  // copy existing pairs to new array
    }
    for(int i = m_index; i < m_size; i++) // initialize remaining elements
    {
        newData[i] = Pair();
    }
    delete[] m_data;  // free memory from old array
    m_data = newData; // assign pointer of old data to new data
}

void sortedArray::returnArray(){
    for(int i = 0; i < m_index; i++)
    {
        std::cout<<m_data[i]<< ": "<<m_data[i].getCounter()<<std::endl;
    }
}

int sortedArray::getSize(){
    return m_size;
}

int sortedArray::getDistinctPairCount(){
   return m_index;
}

int sortedArray::getTotalPairCount(){
    return m_total;
}