#include <chrono>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

// merge two sorted halves a[lo..mid] and a[mid+1..hi]
void merge(std::vector<int> &a, int lo, int mid, int hi) {
    std::vector<int> tmp;
    int i = lo, j = mid + 1;
    while (i <= mid && j <= hi) tmp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= hi)  tmp.push_back(a[j++]);
    for (int k = 0; k < tmp.size(); k++) a[lo + k] = tmp[k];
}

void mergeSort(std::vector<int> &a, int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(a, lo, mid);
    mergeSort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
}

int main() {
    const int N = 2000000;
    std::vector<int> a(N);
    for (int &x : a) x = rand() % 1000000;
    std::vector<int> b = a;   // same data for both tests

    // 1) One thread
    auto start = std::chrono::steady_clock::now();
    mergeSort(a, 0, N - 1);
    auto end = std::chrono::steady_clock::now();
    std::cout << "One thread  : "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    // 2) Two threads: each sorts one half, then we merge the halves
    start = std::chrono::steady_clock::now();
    int mid = (N - 1) / 2;
    std::thread t1(mergeSort, std::ref(b), 0, mid);
    std::thread t2(mergeSort, std::ref(b), mid + 1, N - 1);
    t1.join();
    t2.join();
    merge(b, 0, mid, N - 1);
    end = std::chrono::steady_clock::now();
    std::cout << "Two threads : "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    std::cout << "Same result : " << (a == b ? "yes" : "no") << std::endl;
    return 0;
}