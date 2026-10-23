#include <iostream>

void swapNumbers(int &num1, int &num2);

int main() {
    int a, b;

    std::cout << "Enter first number (A): ";
    std::cin >> a;
    std::cout << "Enter second number (B): ";
    std::cin >> b;

    std::cout << "\nBefore swap: A = " << a << ", B = " << b << std::endl;

    swapNumbers(a, b);

    std::cout << "After swap:  A = " << a << ", B = " << b << std::endl;


    return 0;
}

void swapNumbers(int &num1, int &num2) {

    int temp = num1;
    num1 = num2;
    num2 = temp;
}

