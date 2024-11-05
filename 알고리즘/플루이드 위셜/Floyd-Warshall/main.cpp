#include <iostream>
#include <vector>
#include <climits>

#define NUM_NODE 6
#define INT_MAX 2147483647

void floydWarshall(int graph[NUM_NODE][NUM_NODE]) {
    int dist[NUM_NODE][NUM_NODE];

    // Initialize the distance array with the given graph values
    for (int i = 0; i < NUM_NODE; ++i) {
        for (int j = 0; j < NUM_NODE; ++j) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < NUM_NODE; ++k) {
        for (int i = 0; i < NUM_NODE; ++i) {
            for (int j = 0; j < NUM_NODE; ++j) {
                // 
                if (?? &&  // 조건1. k를 거치는 길이 연결되어 있고
                    ?? &&  // 조건2. k로 부터 목적지로 가는길이 연결되어 있을때
                    ??)  // 조건3. i -> j 로 가는 조건 
                {
                    ??;  
                    //
                }
            }
        }
    }

    // Print the shortest distance matrix
    std::cout << "Shortest distances between every pair of nodes:\n";
    for (int i = 0; i < NUM_NODE; ++i) {
        for (int j = 0; j < NUM_NODE; ++j) {
            if (dist[i][j] == INT_MAX)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int graph[NUM_NODE][NUM_NODE] = {
        
    };

    floydWarshall(graph);

    return 0;
}
