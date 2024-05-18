#include "myFile.h"

myFile::myFile(){}

myFile::myFile(const std::string& filename){
    m_filename = filename;
}

std::string myFile::cleanWord(const std::string& word){
    std::regex pattern("[^a-zA-Z]");  // regular expression pattern to match non-alphabetic characters
    std::string clean = std::regex_replace(word, pattern, "");  // remove non-alphabetic characters
    std::transform(clean.begin(), clean.end(), clean.begin(), [](char c){ return std::tolower(c); });  // convert to lowercase
    return clean;
}

void myFile::cleanAndSaveToFile(const std::string& inputFilename, const std::string& outputFilename){
    std::ifstream inputFile(inputFilename);
    if(!inputFile){ // check for validity of input file
        std::cerr << "Failed to open input file: " << inputFilename << std::endl;
        return;
    }
    std::ofstream outputFile(outputFilename);
    if(!outputFile){
        std::cerr << "Failed to open output file: " << outputFilename << std::endl;
        inputFile.close();
        return;
    }
    std::string word;
    while(inputFile >> word){
        std::string cleanedWord = cleanWord(word);
        outputFile << cleanedWord << " ";
    }
    inputFile.close();
    outputFile.close();
    std::cout << "Cleaned file saved successfully." << std::endl;
}

Pair* myFile::createRandomPairArray(const std::string& filename, int numPairs){
    Pair* randomPairs = new Pair[numPairs];
    std::ifstream file(filename);
    if(!file){
        std::cout << "Failed to open the file: " << filename << std::endl;
        delete[] randomPairs;  // Clean up the allocated memory
        return nullptr;
    }
    std::string word;
    std::string prevWord;
    size_t pairCount = 0;

    // std::random_device rd; <-- creates random number generator that will be used as a seed if we want random array of pairs each time
    std::mt19937 gen(13); // use 13 as seed to create random numbers OR rd if we uncomment above line
    std::uniform_real_distribution<double> dist(0.0, 1.0);  // create random floating numbers with normal distribution
    while(file >> word && pairCount < numPairs){
        // Add a pair with a low probability (0.01)
        if(dist(gen) < 0.01){
            randomPairs[pairCount] = Pair(prevWord, word);
            ++pairCount;
        }
        prevWord = word;
    }
    file.close();
    return randomPairs;
}
