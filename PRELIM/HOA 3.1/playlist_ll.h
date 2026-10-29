#ifndef PLAYLIST_LL_H
#define PLAYLIST_LL_H

#include <iostream>
#include <string>

//node for a song
template <typename T>
class CircularList{
    public:
    T data;
    CircularList<T>* next = nullptr;
};

//add a song
template <typename T>
void cllInsertEnd(T newData, CircularList<T>** head){

    //make the new node
    CircularList<T>* newNode = new CircularList<T>;
    newNode->data = newData;

    //if playlist is empty, new node points to itself
    if(*head == nullptr){
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    //find the last node by walking until we get back to head
    CircularList<T>* temp = *head;
    while(temp->next != *head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

//remove a song by its name?
template <typename T>
void cllDeleteNode(T findData, CircularList<T>** head){

    if(*head == nullptr){
        std::cout<<"the playlist is empty\n";
        return;
    }

    CircularList<T>* curr = *head;
    CircularList<T>* prev = nullptr;

    //just one song in the playlist
    if(curr->next == curr && curr->data == findData){
        delete curr;
        *head = nullptr;
        return;
    }

    bool found = false;
    do{
        if(curr->data == findData){
            found = true;
            break;
        }
        prev = curr;
        curr = curr->next;
    } while(curr != *head);

    if(!found){
        std::cout<<"song not found\n";
        return;
    }

    //if we're deleting the head, we need to fix the last node's next too
    if(curr == *head){
        //find the last node
        CircularList<T>* last = *head;
        while(last->next != *head){
            last = last->next;
        }
        *head = curr->next;
        last->next = *head;
    } else {
        prev->next = curr->next;
    }

    delete curr;
}

//play every song once around the loop
template <typename T>
void cllPlayAll(CircularList<T>* head){
    if(head == nullptr){
        std::cout<<"the playlist is empty\n";
        return;
    }

    CircularList<T>* temp = head;

    std::cout<<"Now playing: \n";
    do{
        std::cout<<temp->data<<" -> ";
        temp = temp->next;
    } while(temp != head);

    std::cout<<"(back to start)\n";
}

//go to the next song
template <typename T>
CircularList<T>* cllNext(CircularList<T>* current){
    if(current == nullptr){
        std::cout<<"the playlist is empty\n";
        return nullptr;
    }
    return current->next;
}

//go to the previous song
//to find the song right before the current one
template <typename T>
CircularList<T>* cllPrevious(CircularList<T>* current){
    if(current == nullptr){
        std::cout<<"the playlist is empty\n";
        return nullptr;
    }

    if(current->next == current){
        return current; //only one song
    }

    CircularList<T>* temp = current;
    while(temp->next != current){
        temp = temp->next;
    }
    return temp;
}

#endif