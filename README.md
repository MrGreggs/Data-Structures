# Data-Structures
This project is a collection of fundamental data structures implemented from scratch in C++. The program preprocesses a text file by "cleaning" the words—converting all words to lowercase and removing any non-alphanumeric characters. It then creates pairs of words and stores them in the selected data structure.

This serves as a learning exercise to understand and create the underlying mechanisms of data structures. The project was part of a Data Structures course.

# Implemented Data Structures
1. Unsorted Array
2. Sorted Array
3. Binary Tree
4. AVL Tree
5. Hashtable

Each implementation focuses on fundamental operations such as insertion, deletion, traversal, and search, demonstrating the core principles of data structure design and manipulation.

# Compilation and Execution
To compile the program, execute the following command in the terminal:
`g++ -g -o main main.cpp myFile.cpp Pair.cpp Node.cpp sortedArray.cpp unsortedArray.cpp binaryTree.cpp AVL.cpp hashTable.cpp`

After the executable is created, run it with:
`./main _dataStructure_ _filename_`
Replace <data_structure_number> with a number from 1 to 5 to select the data structure:

1: Unsorted Array
2: Sorted Array
3: Binary Tree
4: AVL Tree
5: Hashtable
Replace <filename> with the name of the text file to be processed.

For example, to run the program using the Binary Tree on small-file.txt:
`./main 3 small-file.txt`

The preprocessing command should be commented out after the text file has been processed once to reduce execution time. The variable numPairs defines the number of pairs to be created from the given text file.

# Ouput
The output consists of the time taken to create the data structure by reading the text file string by string and storing the pairs appropriately. Next, it searches numPairs pairs in the data structure and prints out the search time.
