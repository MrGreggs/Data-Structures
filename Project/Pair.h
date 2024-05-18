#ifndef PAIR_H
#define PAIR_H
#include <iostream>
#include <string>

class Pair{
    public:
        Pair(); // empty constructor
        Pair(std::string first, std::string second); //constructor
        ~Pair(); // destructor
        std::string getPair() const;  // return first, second   
        std::string getFirst() const; // return first word
        std::string getSecond() const; // return second word
        bool isReal();      // return if pair is real or if it is trash value
        void updateCounter(); // increment counter by 1
        void setCounter(int value); 
        int getCounter(); // return occurences of pair in the data structure
        void setReal(bool real);  // set value for isReal
        // overloaded operators
        friend std::ostream& operator<<(std::ostream& os, const Pair& p);
        friend bool operator==(const Pair& p1, const Pair& p2);
        friend bool operator!=(const Pair& p1i, const Pair& p2);
        friend bool operator>(const Pair& p1, const Pair& p2);
        friend bool operator<(const Pair& p1, const Pair& p2);   
        Pair& operator=(const Pair& other); 
    private: // each pair contains 2 words, a counter to keep track of occurences and a bool value
             // to check if the pair in the data structure is real or trash (used only in the hashtable)
        std::string m_first;
        std::string m_second;
        int m_counter;
        bool m_isReal;
};
#endif