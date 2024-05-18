#include "hashTable.h"

hashTable::hashTable() : m_index(0), m_total(0), m_size(0) {};

hashTable::hashTable(unsigned long initialSize) : m_index(0), m_total(0){
    m_size = initialSize;
    m_data = new Pair[m_size];
    for (unsigned long i = 0; i < m_size; i++) {
        m_data[i] = Pair();
    }
}

hashTable::~hashTable(){
    delete[] m_data;
}

unsigned long hashTable::newTableSize(){

    bool found = true;
    int newSize = 2 * m_size + 1; // make it odd because oldSize is a prime
    do{
        int x = sqrt(newSize);
        for(int i = 3; i <= x; i += 2){
            if(newSize % i == 0){
                newSize = newSize + 2;
                x = sqrt(newSize);
                break;
            }
            else{
                found = true;
            }
        }
    }while(!found);
    return newSize;
}

double hashTable::loadFactor(){
    return static_cast<double>(m_total) / m_size;
}

unsigned long hashTable::handleCollision(const Pair& pair, unsigned long position){
    unsigned long i = 1;
    m_collisions++;
    unsigned long newPosition = (position + i * hashFunction2(pair)) % m_size;
    unsigned long maxIterations = m_size; // maximum number of iterations allowed

    while(m_data[newPosition].isReal() && maxIterations > 0){
        i++;
        m_collisions++;
        if(m_data[newPosition] == pair){
            m_index--;
            return newPosition;
        }
        newPosition = (position + i * hashFunction2(pair)) % m_size;
        maxIterations--;
    }
    return newPosition;
}

int hashTable::searchPair(const Pair& pair){
    unsigned long position = hashFunction(pair);
    if(pair == m_data[position]){
        return m_data[position].getCounter(); // successfully found pair and returned its counter
    }
    return -1; // wrong pair
}

int hashTable::getCollisions(){
    return m_collisions;
}

bool hashTable::insertPair(const Pair& pair){
    unsigned long position = hashFunction(pair);

    if(!m_data[position].isReal()){
        // pair is not a collision, insert it
        m_data[position] = pair;
        m_data[position].setReal(true);
        m_data[position].setCounter(1);
        m_index++;
        m_total++;
        if(loadFactor() > 0.5){
            rehashTable();
        }
        return true;
    } 
    else if(m_data[position].isReal() && (m_data[position] == pair)){
        // pair is a duplicate, update its counter
        m_data[position].updateCounter();
        m_total++;
        return true;
    } 
    else{
        // pair is a collision, handle it
        unsigned long newPosition = handleCollision(pair, position);
        m_data[newPosition] = pair;
        m_data[newPosition].setReal(true);
        m_data[newPosition].setCounter(1);
        m_index++;
        m_total++;
        if(loadFactor() > 0.5){
            rehashTable();
        }
        return true;
    }
}

unsigned long hashTable::hashFunction2(const Pair& pair){
    std::string bigWord = pair.getFirst() + pair.getSecond(); // concatenate the strings of the pairs
    unsigned long hash = 0;
    for(char c : bigWord){
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return hash % m_size;
}

// Jenkins's one_at_a_time by Bob Jenkins
unsigned long hashTable::hashFunction(const Pair& pair){
    std::string bigWord = pair.getFirst() + pair.getSecond(); // concatenate the strings of the pairs
    unsigned long hash = 0;
    unsigned long length = bigWord.size();
    unsigned long i = 0;
    while(i < length){
        hash += bigWord[i++]; // add character's ASCII value to hash
        hash += hash << 10;  // left-shift it by 10 bits
        hash ^= hash >> 6;   // perform a bit-wise XOR on a right-shifted by 6 bits version of hash
    }
    hash += hash << 3;   // left-shift by 3 bits and add it to hash
    hash ^= hash >> 11;  // perform a bit-wise XOR on a right-shifted by 11 bits version of hash
    hash += hash << 15;  // left-shift by 15 bits and add it to hash
    return hash % m_size;
}

void hashTable::rehashTable() {
    std::cout << "Resizing..." << std::endl;
    unsigned long newSize = newTableSize(); // create new table with appropriate size
    unsigned long oldSize = m_size;

    Pair* newData = new Pair[newSize];
    std::swap(m_data, newData);  // swap only the pointers of the tables, not the data itself
    m_index = 0;                 // in order to reduce the cost of data copied from old table to new
    m_total = 0;    
    m_size = newSize;

    for(unsigned long i = 0; i < oldSize; i++){
        if (newData[i].isReal()) {   // iterate through the old table and insert valid pairs into the new table
            insertPair(newData[i]);  // and insert the pairs from newData[i] which is the old table 
        }                            // to m_data which is the new table
    }
    delete[] newData; // free the memory of the old table
}

int hashTable::getDistinctPairCount(){
    return m_index;
}

int hashTable::getTotalPairCount(){
    return m_total;
}
