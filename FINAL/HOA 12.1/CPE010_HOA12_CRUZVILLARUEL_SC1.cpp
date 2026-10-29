#include <iostream>

int mat[100][100];   // the matrix

// counts the paths from (0,0) to (i,j) that have the given cost
int countPaths(int i, int j, int cost) {

    // outside the matrix or cost is already negative
    if (i < 0 || j < 0 || cost < 0)
        return 0;

    // reached the first cell
    if (i == 0 && j == 0) {
        if (cost == mat[0][0])
            return 1;   // the path has the exact cost
        else
            return 0;
    }

    // a cell can be reached from the top or from the left
    return countPaths(i - 1, j, cost - mat[i][j]) + // subtract the current cell's value from the cost
           countPaths(i, j - 1, cost - mat[i][j]);
}

int main() {
    int M, N, cost;

    std::cout << "Enter rows and columns: ";
    std::cin >> M >> N;

    // input the matrix
    std::cout << "Enter the matrix:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> mat[i][j];
        }
    }

    std::cout << "Enter target cost: ";
    std::cin >> cost;

    // start from the last cell (M-1, N-1)
    int result = countPaths(M - 1, N - 1, cost);

    std::cout << "Number of paths with cost " << cost << " = " << result << std::endl;

    return 0;
}