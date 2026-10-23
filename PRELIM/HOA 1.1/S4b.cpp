#include <iostream>

class Triangle {
private:
    double totalAngle, AngleA, AngleB, AngleC;
    double Height, Base, totalArea;
    double SideA, SideB, SideC, PerimeterTotal;

public:
    Triangle(double A, double B, double C);
    double Area(double D, double E);
    double Perimeters(double F, double G, double H);
    void setAngles(double A, double B, double C);
    void setArea(double D, double E);
    void setPerimeters(double F, double G, double H);
    void triangleClassification();
    const bool validateTriangle();
};

Triangle::Triangle(double A, double B, double C) {
    AngleA = A;
    AngleB = B;
    AngleC = C;
    totalAngle = A + B + C;
}

double Triangle::Area(double D, double E) {
    Base = D;
    Height = E;
    totalArea = 0.5 * Base * Height;
    return totalArea;
}

double Triangle::Perimeters(double F, double G, double H) {
    SideA = F;
    SideB = G;
    SideC = H;
    PerimeterTotal = F + G + H;
    return PerimeterTotal;
}

void Triangle::setAngles(double A, double B, double C) {
    AngleA = A;
    AngleB = B;
    AngleC = C;
    totalAngle = A + B + C;
}

void Triangle::setArea(double D, double E) {
    Base = D;
    Height = E;
    totalArea = 0.5 * Base * Height;
}

void Triangle::setPerimeters(double F, double G, double H) {
    SideA = F;
    SideB = G;
    SideC = H;
    PerimeterTotal = F + G + H;
}

void Triangle::triangleClassification() {
    // Fixed the comma operator bug to properly check each angle individually
    if (AngleA < 90 && AngleB < 90 && AngleC < 90) {
        std::cout << "This Triangle is Acute-Angled" << std::endl;
    } else if (AngleA == 90 || AngleB == 90 || AngleC == 90) {
        std::cout << "This Triangle is Classified as 'Others'." << std::endl;
    } else {
        std::cout << "This Triangle is Obtused-Angled." << std::endl;
    }
}

const bool Triangle::validateTriangle() {
    // A strict triangle validation checks if the exact sum of internal angles equals 180
    return (totalAngle == 180);
}

int main() {
    Triangle set1(40, 30, 110);
    
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }
    
    std::cout << "Therefore, ";
    set1.triangleClassification();
    
    double area = set1.Area(10, 6);
    std::cout << "The Area of the Triangle is: " << area << std::endl;
    
    double perimeter = set1.Perimeters(25, 15, 20);
    std::cout << "The Perimeter of a Triangle is: " << perimeter << std::endl;
    
    return 0;
}