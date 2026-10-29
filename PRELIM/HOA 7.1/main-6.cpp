//Cruz, Elijah J. - CPE21S2
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingAlgo.h"

const int maxSize = 100;
const int candidCount = 5;

void displayArr(int arr[]);
void countVotes(int arr[], int counts[]);
int findWinner(int counts[]);

int main(){

    int votes[maxSize];
    int counts[candidCount] = {0};
    srand(time(0));

    for(int i = 0; i < maxSize; i++){
        votes[i] = rand() % 5 + 1;
    }

    //display the randomly generated votes
    std::cout<<"\n unsorted votes: \n";
    displayArr(votes);

    bubbleSort(votes, maxSize);
    std::cout<<"\n sorted votes: \n";
    displayArr(votes);

    //search the sorted array and tally the votes per candidate
    countVotes(votes, counts);
    for(int c = 0; c < candidCount; c++){
        std::cout<<"candidate "<<(c+1)<<": "<<counts[c]<<" votes\n";
    }

    //find the candidate with the highest number of votes
    int winner = findWinner(counts);
    std::cout<<"The winning candidate is candidate "<< winner + 1 <<" with "<< counts[winner] <<" votes\n";

    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < maxSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void countVotes(int arr[], int counts[]) {
    //for every candidate number, search the whole array and count the matches
    for (int c = 1; c <= candidCount; c++) {
        int total = 0;
            for (int i = 0; i < maxSize; i++) {
                if (arr[i] == c) {
                total++;
            }
        }
        counts[c-1] = total;
    }
}

int findWinner(int counts[]) {
    int winnerIndex = 0;
        for (int c = 1; c < candidCount; c++) {
            if (counts[c] > counts[winnerIndex]) {
            winnerIndex = c;
        }
    }
    return winnerIndex;
}