#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main () {
    /*
    int dataset[max_size];
    srand(time(0));
    for (int i = 0; i < max_size; i++) {
        dataset[i] = rand();
        std::cout << dataset[i] << " ";
    }
    std::cout << std::endl;

    // user input that determines as well if searching is successful or not
    std::cout << "what number to find: ";
    int choice;

    std::cin >> choice;
    linearSearchAR(max_size, choice, dataset);

    //Create a node for your name

    Node<char> *name1 = newNode('J');
    Node<char> *name2 = newNode('I');
    Node<char> *name3 = newNode('M');
    Node<char> *name4 = newNode('L');
    Node<char> *name5 = newNode('O');
    Node<char> *name6 = newNode('R');
    Node<char> *name7 = newNode('D');

    //CONNECT THE NODES
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = name7;


    //std::cout << "\n Linear Search LL \n";
    //linearSearchLL(name1, 'D');
    // Linear searching
    */

    //generate a sorted array (use for loop)
    int newArr[max_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < max_size; i++) {
        newArr[i] = i;
        std::cout << newArr[i] << " ";
    }
    binarySearchArr(newArr, 10, 4);

    p1();
    p2();
    p3();

}