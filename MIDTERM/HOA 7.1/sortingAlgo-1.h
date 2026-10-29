//Cruz, Elijah J. - CPE21S2
#ifndef SORTING_ALGORITHM_SORTINGALGO_H
#define SORTING_ALGORITHM_SORTINGALGO_H

template <typename T>
void bubbleSort(T arr[], size_t arrSize) {
    //step1: for i = 0 to N - 1 repeat inner loop
    for (int i = 0; i < arrSize; i++) {
        //step 2 inner loop that for K = i + 1 to N - 1 repeat
        for (int j = i + 1; j < arrSize; j++) {
            //step 3 swap if the arr[j] > arr[i]
            if (arr[i] > arr[j]) {
                //swap arr[j] array[i]
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T>
//array, current position, size of array
int  routineSmallest(T arr[], int K, const int arrSize) {
    int position = K;
    T smallest = arr[K];
    for (int j = K + 1; j < arrSize; j++) {
        if (arr[j] < smallest) {
            smallest = arr[j];
            position = j;
        }
    }
    return position;
}

template <typename T>
// POS = POSITION
void selectionSort(T arr[], size_t arrSize) {
    int POS, temp, pass;
    for(pass = 0; pass < arrSize; pass++) {
        POS = routineSmallest(arr, pass, arrSize);
        //swapping
        if (POS != pass) {
            temp = arr[pass];
            arr[pass] = arr[POS];
            arr[POS] = temp;

            //for verification and counting of number ofg passes
            pass++;
        }
    }
}

template <typename T>
void insertionSort(T arr[], size_t arrSize) {
    int K = 0, J, temp;

    while (K < arrSize) {
        temp = arr[K];
        J = K - 1;
        while (J >= 0 && temp < arr[J]) {
            arr[J+1] = arr[J];
            J--;
        }

        arr[J+1] = temp;
        K++;
    }
}
#endif //SORTING_ALGORITHM_SORTINGALGO_H