#include <iostream>

double DistanceSq(double x1, double y1, double x2, double y2);

int main() {
    double x1, y1, x2, y2;

    std::cout << "Enter coordinates for Point 1 (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Enter coordinates for Point 2 (x2 y2): ";
    std::cin >> x2 >> y2;

    std::cout << "Squared Distance: " << DistanceSq(x1, y1, x2, y2) << std::endl;

    return 0;
}

double DistanceSq(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return (dx * dx) + (dy * dy);
}
