#ifndef UNSORTEDARRAY_H
#define UNSORTEDARRAY_H
#include "Pair.h"

class unsortedArray{
    public:
        unsortedArray();
        unsortedArray(unsigned long initialSize); // create dynamic unsorted array
        ~unsortedArray();
        int getSize(); // return total size
        int checkPair(const Pair& p); // check if one pair exists in the array
        void insertPair(const Pair& p); // insert pair
        int searchPair(Pair p); // find pair and return its counter
        void resizeArray(); // resize array if full
        void returnArray(); // return the values of the unsorted array
        int getDistinctPairCount(); // return distinct amount of pairs
        int getTotalPairCount(); // return all the pairs' counters
    private:
            int m_size;
            Pair* m_data;
            int m_index;
            int m_total;
};
#endif