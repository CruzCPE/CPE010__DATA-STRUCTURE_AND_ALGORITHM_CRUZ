#include <iostream>
#include <chrono> // for timing

// linear power - subtracts 1 each time
double rpower(double x, int n) {
    if (n == 0) return 1.0;
    return x * rpower(x, n - 1);
}

// binary power - divides n by 2 each time
double brpower(double x, int n) {
    if (n == 0) return 1.0;
    if (n % 2 != 0) { // odd
        double y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else { // even
        double y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    double x = 2.0;
    int test_values[] = {8, 16, 1024};

    for (int n : test_values) {
        std::cout << "n = " << n << " \n";

        // Measure rpower runtime
        auto start1 = std::chrono::high_resolution_clock::now();
        double res1 = rpower(x, n);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> time1 = end1 - start1;

        // Measure brpower runtime
        auto start2 = std::chrono::high_resolution_clock::now();
        double res2 = brpower(x, n);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> time2 = end2 - start2;

        std::cout << "rpower time : " << time1.count() << " microseconds\n";
        std::cout << "brpower time: " << time2.count() << " microseconds\n\n";
    }

    return 0;
}

