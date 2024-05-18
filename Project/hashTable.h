#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cmath>
#include "Pair.h"

class hashTable{
    public:
        hashTable();
        hashTable(unsigned long initialSize);
        ~hashTable();
        unsigned long handleCollision(const Pair& pair, unsigned long position);
        unsigned long newTableSize();
        int searchPair(const Pair& pair); // search pair and return its counter
        bool insertPair(const Pair& pair);
        unsigned long hashFunction(const Pair& pair);
        unsigned long hashFunction2(const Pair& pair);
        unsigned long hashFunction3(const Pair& pair);
        unsigned long hashFunction4(const Pair& pair);
        int getCollisions();
        double loadFactor();
        void rehashTable(); // if load factor > 0.5, resize and rehash table
        int getDistinctPairCount(); // returns number of distinct pairs
        int getTotalPairCount(); // return total amount of pairs 

    private:
        int m_total;
        int m_index;
        unsigned long m_size;
        int m_collisions;
        Pair* m_data;


};

#endif