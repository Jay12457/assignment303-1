#include "ArrayManager.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

// Function to read data from a file into an array
void ArrayManager::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("File not found or could not be opened.");
    }

    int value;
    while (file >> value) {
        data.push_back(value);
    }
}

// Function to check if a certain integer exists in the array and return its index
int ArrayManager::findInteger(int target) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            return i;
        }
    }
    return -1; // Integer not found
}

// Function to modify the value of an integer at a given index
std::pair<int, int> ArrayManager::modifyValue(int index, int newValue) {
    try {
        if (index >= 0 && index < data.size()) {
            int oldValue = data[index];
            data[index] = newValue;
            return std::make_pair(oldValue, newValue);
        } else {
            throw std::out_of_range("Index out of bounds.");
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return std::make_pair(-1, -1); // Indicate error with -1 values
    }
}

// Function to add a new integer to the end of the array
void ArrayManager::addInteger(int value) {
    data.push_back(value);
}

// Function to replace a value at a given index with a new value or remove it
void ArrayManager::replaceOrRemove(int index, int newValue) {
    try {
        if (index >= 0 && index < data.size()) {
            data[index] = newValue;
        } else {
            throw std::out_of_range("Index out of bounds.");
        }
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to print the current contents of the array
void ArrayManager::printArray() {
    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
