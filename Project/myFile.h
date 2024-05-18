#ifndef MY_FILE_H
#define MY_FILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <regex>
#include <vector>
#include <random>
#include <chrono>
#include "Pair.h"

class myFile{
    public:
        myFile();
        myFile(const std::string& fileName); // create myFile with given filename
        std::string cleanWord(const std::string& word); // "cleans" words from non-alphabetic characters and converts them to lowercase
        void cleanAndSaveToFile(const std::string& inputFilename, const std::string& outputFilename);
        Pair* createRandomPairArray(const std::string& filename, int numPairs); // create an array of Q pairs from file
        template <typename T> // template function that creates the given data structure
        void processText(T& dataStructure){ // by inserting the cleaned pairs from a txt file
            std::ifstream inputFile(m_filename);
            if(!inputFile){
                std::cerr << "Failed to open file: " << m_filename << std::endl;
                return;
            }
            // create previous and current words
            std::string previousWord;
            std::string currentWord;
            inputFile >> previousWord;
            while(inputFile >> currentWord){
                // keep reading words and create pair
                Pair pair(previousWord, currentWord);
                dataStructure.insertPair(pair);
                // change position of index to current word
                previousWord = currentWord;
            }
            inputFile.close();
        }
    private:
        std::string m_filename;
};
#endif
