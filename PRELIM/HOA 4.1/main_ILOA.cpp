#include <iostream>
#include <stack>

int main() {

    std::stack<int> stack1, stack2;

    //stack 1
    std::cout << "Testing the Stack STL: " <<std::endl;

    //isEmpty
    std::cout << "The Stack is currently empty?: " << stack1.empty() << std::endl;

    //Emplace
    std::cout << "You a newly created stack added: " << stack1.emplace(11) << std::endl;

    //Push
    stack1.push(10);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(9);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(8);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(7);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;
    stack1.push(6);
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;

    //Pop
    std::cout << "Pop testing: " << std::endl;

    std::cout << "The current size of the stack is: " << stack1.size() << std::endl;

    stack1.pop();
    std::cout << "The top of the stack is: " << stack1.top() << std::endl;


    std::cout << std::endl;

    // Stack 2

    //isEmpty
    std::cout << "The Stack is currently empty?: " << stack2.empty() << std::endl;

    //Push
    stack2.push(5);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;
    stack2.push(4);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;
    stack2.push(3);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;
    stack2.push(2);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;
    stack2.push(1);
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;

    //Emplace
    std::cout << "You a newly created stack added: " << stack2.emplace(75) << std::endl;

   //Pop
    std::cout << "The current size of the stack is: " << stack2.size() << std::endl;

    std::cout << "Pop testing: " << std::endl;

    stack2.pop();
    std::cout << "The top of the stack is: " << stack2.top() << std::endl;

    std::cout << "Swap Testing: " << std::endl;
    stack1.swap(stack2);
    stack2.swap(stack1);

    //Display
    std::cout << "Stack 1: ";
        while (!stack1.empty()) {
            std::cout << stack1.top() << " ";
            stack1.pop();
        }


        //Display
    std::cout << "Stack 2:";
        while (!stack2.empty()) {
            std::cout << stack2.top() << " ";
            stack2.pop();
        }



    return 0;

}