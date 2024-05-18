#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include "Pair.h"

struct searchResult{
    int m_position;
    bool m_found;
};

class sortedArray{   
    public:
        sortedArray();
        sortedArray(unsigned long initialSize); // create dynamic sorted array
        ~sortedArray();
        int getSize(); // return total size
        searchResult binarySearch(const Pair& p); // return position of pair if it is already inserted, else -1
        void insertPair(Pair p);
        int getDistinctPairCount(); // return the amount of distinct inserted pairs
        int checkPair(Pair p); // search pair and return its position
        int searchPair(const Pair& p); // search pair and return its counter
        void resizeArray(); // resize if array is full
        void returnArray(); // returns the values of the array
        int getTotalPairCount(); // return total amount of pairs
    
    private:
        int m_size;
        Pair* m_data;
        int m_index;
        int m_total;
};
#endif