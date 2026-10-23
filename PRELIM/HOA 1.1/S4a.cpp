#include <iostream>

// 1. Class Declaration
class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;

public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    bool validateTriangle() const; 
    
    double computeArea(double base, double height) const;
}; 

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

bool Triangle::validateTriangle() const {
    return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
}

// a. Simple Area calculation (Base * Height / 2)
double Triangle::computeArea(double base, double height) const {
    return 0.5 * base * height;
}

int main() {
    Triangle set1(40, 30, 110);
    
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        
        // Print the result of the area function directly
        std::cout << "Area: " << set1.computeArea(10, 5) << "\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }
    
    return 0;
}
