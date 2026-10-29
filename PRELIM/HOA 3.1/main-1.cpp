#include "playlist_ll.h"
#include <iostream>
#include <string>

int main(){

    CircularList<std::string>* playlist = nullptr;
    CircularList<std::string>* current = nullptr;

    //songs for the playlist
    cllInsertEnd<std::string>("I really want to stay at your house", &playlist);
    cllInsertEnd<std::string>("TungTungTungSahu Remix", &playlist);
    cllInsertEnd<std::string>("COCOMELON - Daddy Finger", &playlist);
    current = playlist;

    int choice = 0;
    while(choice != 6){

        std::cout<<"\n==== SONY Song Playlist Menu ====\n";
        std::cout<<"1. Play all songs\n";
        std::cout<<"2. Next song\n";
        std::cout<<"3. Previous song\n";
        std::cout<<"4. Insert song\n";
        std::cout<<"5. Remove song\n";
        std::cout<<"6. Exit\n";
        std::cout<<"Enter choice: ";
        std::cin>>choice;
        std::cin.ignore();

        if(choice == 1){
            cllPlayAll(playlist);
        }
        else if(choice == 2){
            current = cllNext(current);
            if(current != nullptr){
                std::cout<<"Now on: "<<current->data<<std::endl;
            }
        }
        else if(choice == 3){
            current = cllPrevious(current);
            if(current != nullptr){
                std::cout<<"Now on: "<<current->data<<std::endl;
            }
        }
        else if(choice == 4){
            std::string songName;
            std::cout<<"Enter song name to add: ";
            std::getline(std::cin, songName);
            cllInsertEnd<std::string>(songName, &playlist);

            if(current == nullptr){
                current = playlist;
            }
        }
        else if(choice == 5){
            std::string songName;
            std::cout<<"Enter song name to remove: ";
            std::getline(std::cin, songName);
            cllDeleteNode<std::string>(songName, &playlist);

            current = playlist; //reset just to be safe
        }
        else if(choice == 6){
            std::cout<<"Exiting playlist.\n";
        }
        else{
            std::cout<<"invalid choice, try again\n";
        }
    }

    return 0;
}