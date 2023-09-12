#include <iostream>
#include "ArrayManager.h"

int main() {
    ArrayManager arrMgr;

    try {
        arrMgr.readFromFile("data.txt");

        std::cout << "Array contents: ";
        arrMgr.printArray();

        int searchValue = 5;
        int index = arrMgr.findInteger(searchValue);
        if (index != -1) {
            std::cout << searchValue << " found at index " << index << std::endl;
        } else {
            std::cout << searchValue << " not found in the array." << std::endl;
        }

        int modifyIndex = 2;
        int newValue = 42;
        std::pair<int, int> result = arrMgr.modifyValue(modifyIndex, newValue);
        if (result.first != -1) {
            std::cout << "Modified value at index " << modifyIndex << ": Old value = " << result.first
                 << ", New value = " << result.second << std::endl;
        }

        int newValueToAdd = 99;
        arrMgr.addInteger(newValueToAdd);
        std::cout << "Added " << newValueToAdd << " to the end of the array." << std::endl;

        int replaceIndex = 4;
        int replaceValue = 0;
        arrMgr.replaceOrRemove(replaceIndex, replaceValue);
        std::cout << "Replaced value at index " << replaceIndex << " with " << replaceValue << std::endl;

        std::cout << "Updated Array contents: ";
        arrMgr.printArray();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
