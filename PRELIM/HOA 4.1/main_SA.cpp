//main
#include <iostream>
#include <string>
#include "stackList_SA.h"

bool isBalanced(std::string input) {

    while (!isEmpty<char>()) {
        pop<char>();
    }
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        // push opening symbols
        if (c == '(' || c == '[' || c == '{') {
            push<char>(c);
        }

        // handle closing symbols
        else if (c == ')' || c == ']' || c == '}') {

            if (isEmpty<char>()) {
                std::cout << "ERROR: '" << c << "' has nothing to match" << std::endl;
                return false;
            }

            char popped = pop<char>();

            if ((c == ')' && popped != '(') ||
                (c == ']' && popped != '[') ||
                (c == '}' && popped != '{')) {
                std::cout << "ERROR: '" << popped << "' does not match '" << c << "'" << std::endl;
                return false;
                }
        }

        // anything else, just skip it
    }

    if (!isEmpty<char>()) {
        std::cout << "ERROR: symbol left open at the end" << std::endl;
        return false;
    }

    return true;
}

int main() {

    std::string test1 = "(A+B)+(C-D)";
    std::string test2 = "((A+B)+(C-D)";
    std::string test3 = "((A+B)+[C-D])";
    std::string test4 = "((A+B]+[C-D]}";

    std::cout << "TESTING: " << test1 << std::endl;
    std::cout << (isBalanced(test1) ? "VALID" : "INVALID") << std::endl;

    std::cout << "\nTESTING: " << test2 << std::endl;
    std::cout << (isBalanced(test2) ? "VALID" : "INVALID") << std::endl;

    std::cout << "\nTESTING: " << test3 << std::endl;
    std::cout << (isBalanced(test3) ? "VALID" : "INVALID") << std::endl;

    std::cout << "\nTESTING: " << test4 << std::endl;
    std::cout << (isBalanced(test4) ? "VALID" : "INVALID") << std::endl;

    return 0;
}