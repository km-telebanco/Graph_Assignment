#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices

int graph[V][V];

// Function to initialize the graph
void initializeGraph() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Adding the edges with weights
    graph[0][0] = 0;
    graph[0][1] = 4;
    graph[0][2] = 0;
    graph[0][3] = 0;
    graph[0][4] = 0;

    graph[1][0] = 0;
    graph[1][1] = 0;
    graph[1][2] = 3;
    graph[1][3] = 5;
    graph[1][4] = 0;
    
    graph[2][0] = 0;
    graph[2][1] = 0;
    graph[3][2] = 0;
    graph[2][3] = 0;
    graph[2][4] = 3;

    graph[3][0] = 0;
    graph[3][1] = 0;
    graph[3][2] = 2;
    graph[3][3] = 0;
    graph[3][4] = 4;

    graph[4][0] = 0;
    graph[4][1] = 0;
    graph[4][2] = 0;
    graph[4][3] = 0;
    graph[4][4] = 0;
}

// Function to find the minimum distance vertex
int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path from source to destination
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printPath(parent, parent[j]);
    printf(" -> %c", j + 'A');
}

// Function to print the distance and shortest path
void printSolution(int dist[], int parent[], int src, int dest) {
    printf("Shortest Distance from %c to %c: %d\n", src + 'A', dest + 'A', dist[dest]);
    printf("Shortest Path: %c", src + 'A');
    printPath(parent, dest);
    printf("\n");
}

// Function to implement Dijkstra's algorithm
void dijkstra(int src, int dest) {
    int dist[V];     // The output array to store the shortest distance from src to i
    bool visited[V];  // To keep track of vertices included in shortest path tree
    int parent[V];    // Array to store the shortest path tree

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
    if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
        parent[v] = u;
        dist[v] = dist[u] + graph[u][v];
    }
}

    }

    printSolution(dist, parent, src, dest);
}

int main() {
    initializeGraph();
    char startNode, endNode;

    printf("Enter starting node (A-E): ");
    scanf(" %c", &startNode);
    printf("Enter destination node (A-E): ");
    scanf(" %c", &endNode);

    int src = startNode - 'A';
    int dest = endNode - 'A';

    if (src < 0 || src >= V || dest < 0 || dest >= V) {
        printf("Invalid input node(s).\n");
        return 1;
    }

    dijkstra(src, dest);

    return 0;
}
