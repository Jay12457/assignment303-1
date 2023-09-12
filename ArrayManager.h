#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <vector>
#include <string>

class ArrayManager {
private:
    std::vector<int> data;

public:
    // Function to read data from a file into an array
    void readFromFile(const std::string& filename);

    // Function to check if a certain integer exists in the array and return its index
    int findInteger(int target);

    // Function to modify the value of an integer at a given index
    std::pair<int, int> modifyValue(int index, int newValue);

    // Function to add a new integer to the end of the array
    void addInteger(int value);

    // Function to replace a value at a given index with a new value or remove it
    void replaceOrRemove(int index, int newValue);

    // Function to print the current contents of the array
    void printArray();
};

#endif // ARRAY_MANAGER_H
