// Table 14-2
#include <iostream>
#include <chrono>
int a[10000], t[10000];

void fillArray(int n, bool worst) {
    for (int i = 0; i < n; i++) a[i] = worst ? n - i : i;
}

void insertionSort(int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

void mergeSort(int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2, i = lo, j = mid + 1, k = lo;
    mergeSort(lo, mid);
    mergeSort(mid + 1, hi);
    while (i <= mid && j <= hi) t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) t[k++] = a[i++];
    while (j <= hi) t[k++] = a[j++];
    for (k = lo; k <= hi; k++) a[k] = t[k];
}

double timeSort(int n, bool worst, bool merge, int reps) {
    double total = 0;
    for (int r = 0; r < reps; r++) {
        fillArray(n, worst);
        auto s = std::chrono::steady_clock::now();
        if (merge) mergeSort(0, n - 1); else insertionSort(n);
        auto e = std::chrono::steady_clock::now();
        total += std::chrono::duration<double, std::micro>(e - s).count();
    }
    return total / reps;
}

int main() {
    int sizes[] = {100, 1000, 10000}, reps[] = {1000, 100, 5};
    std::cout << "Algorithm 2\n";
    std::cout << "n case insertion(us) merge(us)\n";
    for (int s = 0; s < 3; s++)
        for (int w = 0; w < 2; w++)
            std::cout << sizes[s] << (w ? " worst " : " best ") << timeSort(sizes[s], w, false, reps[s])
                      << " " << timeSort(sizes[s], w, true, reps[s]) << "\n";