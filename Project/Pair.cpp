#include "Pair.h"

Pair::Pair() : m_first(""), m_second(""), m_counter(0), m_isReal(false){};

Pair::Pair(std::string first, std::string second){
    m_first = first;
    m_second = second;
    m_counter = 1;
    m_isReal = true;
}

Pair::~Pair(){}

std::string Pair::getPair() const{
    return m_first + ", " + m_second;
}

std::string Pair::getFirst() const{
    return m_first;
}

std::string Pair::getSecond() const{
    return m_second;
}

void Pair::updateCounter(){
    ++m_counter;
}

void Pair::setCounter(int value){
    m_counter = value;
}

int Pair::getCounter(){
    return m_counter;
}

bool Pair::isReal(){
    return m_isReal;
}

void Pair::setReal(bool real){
    m_isReal = real;
}

// ********************
// overloaded operators

Pair& Pair::operator=(const Pair& other){
    if(this != &other){
        m_first = other.m_first;
        m_second = other.m_second;
        m_counter = other.m_counter;
        m_isReal = other.m_isReal;
    }
    return *this;
}

bool operator==(const Pair& p1, const Pair& p2){
    return (p1.getFirst() == p2.getFirst()) && (p1.getSecond() == p2.getSecond());
}

bool operator!=(const Pair& p1, const Pair& p2){
    return (p1.getFirst() != p2.getFirst()) || (p1.getSecond() != p2.getSecond());
}

bool operator>(const Pair& p1, const Pair& p2){
    if (p1.getFirst() > p2.getFirst())
        return true;
    else if (p1.getFirst() == p2.getFirst() && p1.getSecond() > p2.getSecond())
        return true;
    else
        return false;
}

bool operator<(const Pair& p1, const Pair& p2){
        if(p1.getFirst() < p2.getFirst()) 
            return true;
        else if((p1.getFirst() == p2.getFirst()) && (p1.getSecond() < p2.getSecond()))
            return true;
        else return false;
}

std::ostream& operator<<(std::ostream& os, const Pair& p){
    return os << p.getFirst() << ", " << p.getSecond() << std::endl;
}
