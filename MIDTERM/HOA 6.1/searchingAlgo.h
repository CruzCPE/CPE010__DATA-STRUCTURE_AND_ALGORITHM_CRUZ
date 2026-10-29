#ifndef SEARCHING_ALGORITHM_NODE_H
#define SEARCHING_ALGORITHM_NODE_H
#include <iostream>
#include "node.h"

/*
LINEAR SEARCH ALGORITHM
N -> Boundary of the list
Item -> Searching number
Data -> Linear array
Step 1: I := 0
Step 2: Repeat while I <= n
If (item = data[i])
Print "Searching is successful"
Exit
Else
Print "Searching is Unsuccessful"
Exit
 */

template <typename T>
void linearSearchAR(int size, T dataFind, T array[]) {
    //while loop
    int i = 0;
    int comparisons = 0;
    while (i < size) {
        comparisons++;
        std::cout << "Checking index " << i << ": " << array[i] << " vs " << dataFind << "\n";
        if (dataFind == array[i]) {
            std::cout << "searching is successful (" << comparisons << " comparisons)\n";
            return;
        }
        i++;
    }
    std::cout << "searching is unsuccessful (" << comparisons << " comparisons)\n";
    /*
    //for loop
    for (int i = 0; i < size; i++) {
        if (dataFind == array[i]) {
            std::cout << "searching is successful\n";
            return;
        }
    }
    std::cout << "searching is unsuccessful\n";
    */
}

template <typename T>
void linearSearchLL(Node<T> *nodes, T dataFind) {
    //repeat the loop until the current node is not NULL
    int comparisons = 0;

    while (nodes != nullptr) {
        comparisons++;
        std::cout << "Checking node " << comparisons << ": " << nodes->data << " vs " << dataFind << "\n";
        //check if the item = current node data
        if (nodes->data == dataFind) {
            std::cout << "searching is successful! (" << comparisons << " comparisons)\n";
            return;
        }
        //move on to the next node after
        nodes = nodes->next;
    }
    //display unsuccessful
    std::cout << "searching is unsuccessful! (" << comparisons << " comparisons)\n";
}

/*
BINARY SEARCH ALGORITHM
Step 1: low := 0, up = n-1
Step 2: Repeat while low <= up
mid = int(low+up)/2
if (no = arr[mid])
print "Search element is found!"
exit
else
if (no < arr[mid]) then
up = mid-1
else
low = mid+1
Step 3: Print "Search element is not found"
Step 4: Exit
 */

// problem 3 modified
template <typename T>
void binarySearchArr(T data[],int arrSize,T dataFind){
    int low = 0;
    int high = arrSize - 1;
    int middle;

    while (low <= high){
        middle = (int)((low+high)/2);
        std::cout << "low=" << low << " high=" << high << " middle=" << middle << " data[middle]=" << data[middle] << "\n";
        if (dataFind == data[middle]){
            std::cout << "The data was found: " << dataFind;
            return;
        }
        else if (dataFind < data[middle]){
            high = middle - 1;
        }
        else {
            low = middle + 1;
        }
    }
    std::cout << "The data was not found\n";
}

//middle function getter:
/*
Slow variable moves by one in the loop while fast moves two while
in a loop going through each letter in the name JIMLORD
*/
template <typename T>
Node<T>* getMiddle(Node<T> *start, Node<T> *last) {

    Node<T> *slow = start;
    Node<T> *fast = start;

    //continue until fast reaches the end or the last one of the current search range
    while (fast != last && fast->next != last) {
        //move slow one step
        slow = slow->next;
        //move fast two steps
        fast = fast->next;
        if (fast != last) fast = fast->next;
    }
    return slow;
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind) {
    //step one: set start to the head of the list and set last to null
    Node<T>* last = nullptr;

    //if the middle element is same as key to be searched, we return
    while (start != last) {
        Node<T>* middle = getMiddle(start, last);
        if (middle->data == dataFind) {
            std::cout << "searching is successful\n";
            return;
        }
        //if middle element is less than the key, search the right half
        else if (middle->data < dataFind) {
            start = middle->next;
        }
        //if middle element is greater than the key, search the left half
        else {
            last = middle;
        }
    }
    std::cout << "searching is unsuccessful\n";
}

// Problem 2: sequential search that counts how many times dataFind
// ARRAY
template <typename T>
int countSearchAR(int size, T dataFind, T array[]) {
    int comparisons = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        std::cout << "Checking index " << i << "\n";
        if (dataFind == array[i]) {
            count++;
        }
    }
    std::cout << "found " << count << " occurrences (" << comparisons << " comparisons)\n";
    return count;
}

// Problem 1: sequential search of [15,18,2,19,18,0,8,14,19,14] for key 18
// Runs linearSearchAR and linearSearchLL so you can compare comparisons.
void p1() {
    std::cout << "\nProblem 1\n";
    int size = 10;
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    std::cout << "Array search:\n";
    linearSearchAR(size, 18, arr);

    // build the same list as a linked list, in the same order
    Node<int> *head = newNode(arr[0]);
    Node<int> *tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = newNode(arr[i]);
        tail = tail->next;
    }

    std::cout << "Linked list search:\n";
    linearSearchLL(head, 18);
}
// Problem 2: sequential search that counts how many times dataFind
// LINKED LISTS
template <typename T>
int countSearchLL(Node<T> *nodes, T dataFind) {
    int comparisons = 0;
    int count = 0;
    while (nodes != nullptr) {
        comparisons++;
        std::cout << "Checking node " << comparisons << "\n";
        if (nodes->data == dataFind) {
            count++;
        }
        nodes = nodes->next;
    }
    std::cout << "found " << count << " occurrences (" << comparisons << " comparisons)\n";
    return count;
}

// Problem 2: same list as Problem 1 lang
void p2() {
    std::cout << "\nProblem 2\n";
    int size = 10;
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    std::cout << "Array count:\n";
    countSearchAR(size, 18, arr);

    Node<int> *head = newNode(arr[0]);
    Node<int> *tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = newNode(arr[i]);
        tail = tail->next;
    }

    std::cout << "Linked list count:\n";
    countSearchLL(head, 18);
}

// Problem 3: binary search of sorted list [3,5,6,8,11,12,14,15,17,18]
void p3() {
    std::cout << "\nProblem 3\n";
    int arr[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int size = 10;

    binarySearchArr(arr, size, 8);
}

#endif //SEARCHING_ALGORITHM_NODE_H