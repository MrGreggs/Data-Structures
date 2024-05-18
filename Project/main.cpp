#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include "myFile.h"
#include "Pair.h"
#include "Node.h"
#include "unsortedArray.h"
#include "sortedArray.h"
#include "binaryTree.h"
#include "AVL.h"
#include "hashTable.h"
int main(int argc, char* argv[]) {
  if(argc < 3){
    std::cerr<<"Usage: program_name (eg. ./main) data_structure (1 = unsorted array, 2 = sorted array, 3 = binary search tree, 4 = AVL tree, 5 = hashtable) file_name (e.g. small.txt)"<<std::endl;
    return 1;
  }
  int x = 5;
  int dataStructure = std::stoi(argv[1]); // data structure argument
  std::string fileName = argv[2];         // file name argument
  myFile file(fileName);

  // open the output file in append mode, and save the construction and search time for each data structure
  std::ofstream outputFile("output.txt", std::ios::app);
  if (!outputFile.is_open()){
    std::cerr << "Failed to open the output file." << std::endl;
    return 1;
  }

  // call the cleanAndSaveToFile function if file is not cleaned
  std::string cleanedFileName = "cleaned_" + fileName;
  file.cleanAndSaveToFile(fileName, cleanedFileName);

  // redirect the standard output to the output file
  std::streambuf* coutBuf = std::cout.rdbuf();
  std::cout.rdbuf(outputFile.rdbuf());

  int numPairs = 10000;
  Pair* pairs = file.createRandomPairArray(fileName, numPairs);

  switch(dataStructure){
    case 1:{  
      // unsorted array A
      std::cout<<"UNSORTED ARRAY\n***********************************"<<std::endl;
      auto Astart = std::chrono::high_resolution_clock::now();
      unsortedArray A = unsortedArray(1024);
      file.myFile::processText(A);
      auto Astop = std::chrono::high_resolution_clock::now();
      auto Aduration = std::chrono::duration_cast<std::chrono::milliseconds>(Astop - Astart);

      auto Anewstart = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < numPairs; i++)
        std::cout << "Pair: " <<pairs[i] <<" has: " << A.searchPair(pairs[i]) << " occurences"<<std::endl;
      auto Anewstop = std::chrono::high_resolution_clock::now();
      auto Anewduration = std::chrono::duration_cast<std::chrono::milliseconds>(Anewstop - Anewstart);

      std::cout<<"Duration for construction of unsorted array: "<<Aduration.count()<<" milliseconds"<<std::endl;
      std::cout<<"Duration for search of "<< numPairs<< " pairs in unsorted array: "<<Anewduration.count()<<" milliseconds"<<std::endl;
      break;
  }

    case 2:{
      // sorted array B
      std::cout<<"\nSORTED ARRAY\n***********************************"<<std::endl;
      auto Bstart = std::chrono::high_resolution_clock::now();
      sortedArray B = sortedArray(1024);
      file.myFile::processText(B);
      auto Bstop = std::chrono::high_resolution_clock::now();
      auto Bduration = std::chrono::duration_cast<std::chrono::milliseconds>(Bstop - Bstart);

      auto Bnewstart = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < numPairs; i++)
        std::cout << "Pair: " <<pairs[i] <<" has: " << B.searchPair(pairs[i]) << " occurences"<<std::endl;
      auto Bnewstop = std::chrono::high_resolution_clock::now();
      auto Bnewduration = std::chrono::duration_cast<std::chrono::milliseconds>(Bnewstop - Bnewstart);

      std::cout<<"Duration for construction of sorted array: "<<Bduration.count()<<" milliseconds"<<std::endl;
      std::cout<<"Duration for search of "<< numPairs<< " pairs in sorted array: "<<Bnewduration.count()<<" milliseconds"<<std::endl;
      break;
    }

    case 3:{ 
    // binary tree C
      std::cout<<"\nBINARY SEARCH TREE\n***********************************"<<std::endl;
      auto Cstart = std::chrono::high_resolution_clock::now();
      binaryTree C = binaryTree();
      file.myFile::processText(C);
      auto Cstop = std::chrono::high_resolution_clock::now();
      auto Cduration = std::chrono::duration_cast<std::chrono::milliseconds>(Cstop - Cstart);

      auto Cnewstart = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < numPairs; i++)
        std::cout << "Pair: " <<pairs[i] <<" has: " << C.searchPair(pairs[i]) << " occurences"<<std::endl;
      auto Cnewstop = std::chrono::high_resolution_clock::now();
      auto Cnewduration = std::chrono::duration_cast<std::chrono::milliseconds>(Cnewstop - Cnewstart);

      std::cout<<"Duration for construction of binary search tree: "<<Cduration.count()<<" milliseconds"<<std::endl;
      std::cout<<"Duration for search of "<< numPairs<< " pairs in binary search tree: "<<Cnewduration.count()<<" milliseconds"<<std::endl;
      break;
    }

    case 4:{
    // AVL tree D
      std::cout<<"\nAVL TREE\n***********************************"<<std::endl;
      auto Dstart = std::chrono::high_resolution_clock::now();
      AVL D = AVL();
      file.myFile::processText(D);
      auto Dstop = std::chrono::high_resolution_clock::now();
      auto Dduration = std::chrono::duration_cast<std::chrono::milliseconds>(Dstop - Dstart);

      auto Dnewstart = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < numPairs; i++)
        std::cout << "Pair: " <<pairs[i] <<" has: " << D.searchPair(pairs[i]) << " occurences"<<std::endl;
      auto Dnewstop = std::chrono::high_resolution_clock::now();
      auto Dnewduration = std::chrono::duration_cast<std::chrono::milliseconds>(Dnewstop - Dnewstart);

      std::cout<<"Duration for construction of AVL tree: "<<Dduration.count()<<" milliseconds"<<std::endl;
      std::cout<<"Duration for search of "<< numPairs<< " pairs in AVL tree: "<<Dnewduration.count()<<" milliseconds"<<std::endl;
      break;
    }

    case 5:{
      // hashtable
      std::cout<<"\nHASH TABLE\n***********************************"<<std::endl;
      auto Estart = std::chrono::high_resolution_clock::now();
      hashTable E = hashTable(1024);
      file.myFile::processText(E);
      auto Estop = std::chrono::high_resolution_clock::now();
      auto Eduration = std::chrono::duration_cast<std::chrono::milliseconds>(Estop - Estart);

      auto Enewstart = std::chrono::high_resolution_clock::now();
      for(int i = 0; i < numPairs; i++)
        std::cout << "Pair: " <<pairs[i] <<" has: " << E.searchPair(pairs[i]) << " occurences"<<std::endl;
      auto Enewstop = std::chrono::high_resolution_clock::now();
      auto Enewduration = std::chrono::duration_cast<std::chrono::milliseconds>(Enewstop - Enewstart);

      std::cout<<"Duration for construction of hashtable: "<<Eduration.count()<<" milliseconds"<<std::endl;
      std::cout<<"Duration for search of "<< numPairs<< " pairs in hashtable tree: "<<Enewduration.count()<<" milliseconds"<<std::endl;      
      break;
    }

    default:{
      std::cerr << "Invalid data structure selected" << std::endl;
      return 1;
    }
  }

  return 0;

}
