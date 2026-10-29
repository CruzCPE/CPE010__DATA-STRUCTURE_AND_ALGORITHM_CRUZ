// Table 14-1
#include <iostream>
int a[10000], t[10000];
long long c;

void fillArray(int n, bool worst) {
    for (int i = 0; i < n; i++) a[i] = worst ? n - i : i;
}

void insertionSort(int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            c++;
            if (a[j] <= key) break;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void mergeSort(int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2, i = lo, j = mid + 1, k = lo;
    mergeSort(lo, mid);
    mergeSort(mid + 1, hi);
    while (i <= mid && j <= hi) {
        c++;
        t[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    }
    while (i <= mid) t[k++] = a[i++];
    while (j <= hi) t[k++] = a[j++];
    for (k = lo; k <= hi; k++) a[k] = t[k];
}

int main() {
    std::cout << "Algorithm 1\n";
    std::cout << "n case insertion merge\n";
    for (int n : {100, 1000, 10000})
        for (int w = 0; w < 2; w++) {
            fillArray(n, w); c = 0; insertionSort(n); long long ins = c;
            fillArray(n, w); c = 0; mergeSort(0, n - 1);
            std::cout << n << (w ? " worst " : " best ") << ins << " " << c << "\n";
        }
}