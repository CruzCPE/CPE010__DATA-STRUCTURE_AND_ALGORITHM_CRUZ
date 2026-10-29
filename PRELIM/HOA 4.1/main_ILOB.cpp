#include <iostream>
#include <stack>
#include "stackList_ILOB.h"

int main () {

    std::cout << "PUSHING 'C' 'P' 'E' ONTO THE STACK" << std::endl;
    //push
    push('C');
    push('P');
    push('E');

    //display the current top
    Top<char>(); //top should be 'E'
    displayALL<char>();
    std::cout<<"\nPOPPING ALL THE ELEMENTS"<<std::endl;

    while (!isEmpty<char>()) {
        std::cout<<"POPPED: "<<pop<char>() <<std::endl;
    }

    std::cout<<"\nTESTING THE UNDERFLOW"<<std::endl;
    pop<char>();

    return 0;
}