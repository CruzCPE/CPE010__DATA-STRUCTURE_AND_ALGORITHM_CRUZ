#include <iostream>

double kTempF(double kelvin);

int main() {
    double val1;
    std::cout << "Write the temperature in Kelvin: \n";
    std::cin >> val1;
    
    std::cout << "The temperature in Fahrenheit is: " << kTempF(val1) << std::endl;
    
     return 0; 
} double kTempF(double val1) {
    return (val1 - 273.15) * 1.8 + 32;
    
}
