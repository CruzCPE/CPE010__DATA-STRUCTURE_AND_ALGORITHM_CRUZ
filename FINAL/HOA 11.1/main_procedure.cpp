#include <iostream>
#include <chrono>

// returns true if all elements are unique
bool isUnique(int A[], int n, long long &count) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            count++;
            if (A[i] == A[j]) return false;
        }
    }
    return true;
}

int main() {
    int sizes[] = {1000, 2000, 4000, 8000};
    for (int n : sizes) {
        int *A = new int[n];
        for (int i = 0; i < n; i++) A[i] = i;  // all unique = worst case
        long long count = 0;
        auto start = std::chrono::steady_clock::now();
        isUnique(A, n, count);
        auto end = std::chrono::steady_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "n = " << n << " | comparisons = " << count << " | time = " << time << " microseconds" << std::endl;
        delete[] A;
    }
    return 0;
}