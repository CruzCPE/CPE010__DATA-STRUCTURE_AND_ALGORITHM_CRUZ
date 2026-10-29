#ifndef STACK_LIST_H
#define STACK_LIST_H
#include <iostream>

// Class node that contains data and the next pointer
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
};

// Global pointer for the top of the stack
template <typename T>
Node<T>* head = nullptr;

// Push operation
template <typename T>
void push(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;
}

// Pop operation
template <typename T>
T pop() {
    if (head<T> == nullptr) {
        std::cout << "Stack Underflow" << std::endl;
        return T();
    }
    Node<T>* temp = head<T>;
    T tempVal = temp->data;
    head<T> = temp->next;
    delete temp;
    return tempVal;
}

// isEmpty operation
template <typename T>
bool isEmpty() {
    return head<T> == nullptr;
}

#endif