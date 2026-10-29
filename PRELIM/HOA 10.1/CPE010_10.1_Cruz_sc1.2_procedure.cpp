#include <iostream>

// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

class DiaGraph {
    int N;  // number of nodes in the graph
public:
    int matrix[10][10];     // adjacency matrix
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N) {
        this->N = N;
        // initialize all cells to 0
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix[i][j] = 0;
        // construct directed graph by adding edges to it
        for (int i = 0; i < n; i++) {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;
            matrix[start_ver][end_ver] = weight;
        }
    }
};

// print the adjacency matrix
void display_AdjMatrix(DiaGraph& g, int N)
{
    std::cout << "    ";
    for (int i = 0; i < N; i++)
        std::cout << i << " ";
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        std::cout << i << " | ";
        for (int j = 0; j < N; j++)
            std::cout << g.matrix[i][j] << " ";
        std::cout << std::endl;
    }
}

// graph implementation
int main()
{
    // graph edges array.
    graphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    int N = 6;      // Number of vertices in the graph
    // calculate number of edges
    int n = sizeof(edges)/sizeof(edges[0]);
    // construct graph
    DiaGraph diagraph(edges, n, N);
    // print adjacency matrix representation of graph
    std::cout << "Graph adjacency matrix" << std::endl;
    display_AdjMatrix(diagraph, N);
    return 0;
}