#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <iostream>

//class node that contains data and the next
template <typename T>
class Node {
public:
    T data; //VALUE THAT WE NEED TO STORE
    Node<T>* next; // POINTER TO THE NEXT NODE
};

//global pointer for the top of the stacl
template <typename T>
Node<T> *head = nullptr;

//operations for the stack
// push
template <typename T>
void push(T newData) {
    //create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}
//pop
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout<<"Stack Underflow"<<std::endl;
        return T();
    }
    //save the current top node
    Node<T>* temp = head<T>;
    //store its data
    T tempVal = temp->data;

    //move the head to the next node
    head<T> = temp->next;
    //free the removed node
    delete temp;
    //return the removed value
    return tempVal;
}
// isEmpty
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

// top
template <typename T>
void Top() {
    //error catching:
    if (isEmpty<T>()) {
        std::cout<<"Stack Underflow"<<std::endl;
        return;
    }
    //display the Top node
    std::cout<<"Top of stack is "<<head<T>->data<<std::endl;
}

//display All
template <typename T>
void displayALL() {
    if (head<T> == nullptr) {
        std::cout<<"Stack Underflow\n"<<std::endl;
        return;
    }
    std::cout<<"Displaying the stack: \n";
    Node<T>* temp = head<T>;
    while (temp != nullptr) {
        std::cout<<temp->data<<" \n";
        temp = temp->next;
    }
    std::cout<< "\n"<<std::endl;
}
#endif