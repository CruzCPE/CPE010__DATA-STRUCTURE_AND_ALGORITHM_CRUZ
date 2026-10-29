//Cruz Elijah
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main() {
    const int SIZE = 100;
    int original[SIZE];

    // generate 100 random, unsorted values
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        original[i] = rand() % 1000;
    }

    std::cout << "Preparation Task: Original Unsorted Array" << std::endl;
    printArray(original, SIZE);

    //  Shell Sort
    int shellArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        shellArr[i] = original[i];
    }
    shellSort(shellArr, SIZE);
    std::cout << "\nShell Sort" << std::endl;
    printArray(shellArr, SIZE);

    //  Merge Sort
    int mergeArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        mergeArr[i] = original[i];
    }
    mergeSort(mergeArr, 0, SIZE - 1);
    std::cout << "\nMerge Sort" << std::endl;
    printArray(mergeArr, SIZE);

    //  Quick Sort
    int quickArr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        quickArr[i] = original[i];
    }
    quickSort(quickArr, 0, SIZE - 1);
    std::cout << "\nQuick Sort" << std::endl;
    printArray(quickArr, SIZE);

    return 0;
}