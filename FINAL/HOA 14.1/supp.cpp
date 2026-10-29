// Worst case = the target is NOT in the array.
#include <iostream>
#include <chrono>


int a[100000];
volatile int sink; // stops the compiler from skipping the searches


int linearSearch(int n, int target) {
    for (int i = 0; i < n; i++)
        if (a[i] == target) return i;
    return -1;
}


int binarySearch(int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else                 hi = mid - 1;
    }
    return -1;
}


int main() {
    int sizes[] = {1000, 10000, 100000};


    std::cout << "N\tBinary Search (ns)\tLinear Search (ns)\n";
    for (int s = 0; s < 3; s++) {
        int n = sizes[s];
        for (int i = 0; i < n; i++) a[i] = i; // sorted array 0..n-1
        int target = n; // not in the array -> worst case


        // one search is too fast to time, so repeat and average
        int binaryReps = 100000;
        auto start = std::chrono::steady_clock::now();
        for (int r = 0; r < binaryReps; r++) sink = binarySearch(n, target);
        auto end = std::chrono::steady_clock::now();
        double binaryTime = std::chrono::duration<double, std::nano>(end - start).count() / binaryReps;


        int linearReps = 1000;
        start = std::chrono::steady_clock::now();
        for (int r = 0; r < linearReps; r++) sink = linearSearch(n, target);
        end = std::chrono::steady_clock::now();
        double linearTime = std::chrono::duration<double, std::nano>(end - start).count() / linearReps;


        std::cout << n << "\t" << binaryTime << "\t\t\t" << linearTime << "\n";
    }
    return 0;
}