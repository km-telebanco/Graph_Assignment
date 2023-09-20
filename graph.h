#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "graph_data.h"
#define VERTEX 5 

typedef struct Routes {
    int start;
    int destination;
} Routes;

void AssignNodeNames() {
    for (int i = 0; i < VERTEX; i++) {
        printf("Enter name for Node %c: ", i + 'A');
        scanf("%s", nodeNames[i]);
    }
}

void DisplayGraph() {
    printf("\nGraph (Adjacency Matrix):\n\n");

    printf("    ");
    for (int i = 0; i < VERTEX; i++) {
        printf("%s\t", nodeNames[i]);
    }
    printf("\n");

    for (int i = 0; i < VERTEX; i++) {
        printf("%s\t", nodeNames[i]);

        for (int j = 0; j < VERTEX; j++) {
            if (graph[i][j] == INT_MAX) {
                printf("%d\t", graph[i][j]);
            } else {
                printf("%d\t", graph[i][j]);
            }
        }

        printf("\n");
    }
}

int FindMinDistanceVertex(int shortestDistances[], bool shortestPathSet[]){
    int minDistance = INT_MAX;
    int minVertex;

    for (int vertex = 0; vertex < VERTEX; vertex++) {
        if (!shortestPathSet[vertex] && shortestDistances[vertex] <= minDistance) {
            minDistance = shortestDistances[vertex];
            minVertex = vertex;
        }
    }

    return minVertex;
}

int* EvaluateShortDistance(int graph[][VERTEX], Routes *route){
    int startinglocation = route->start;
    
    static int shortestDistances[VERTEX];
    bool shortestPathSet[VERTEX];

    for (int i = 0; i < VERTEX; i++) { //initialize shortest distance and shortest paths
        shortestDistances[i] = INT_MAX;
        shortestPathSet[i] = false;
    }

    shortestDistances[startinglocation] = 0; // if cebu == cebu = 0 distance

    for (int count = 0; count < VERTEX - 1; count++) {
        int minDistanceVertex = FindMinDistanceVertex(shortestDistances, shortestPathSet);
        shortestPathSet[minDistanceVertex] = true;

        for (int v = 0; v < VERTEX; v++) {
            if (
                !shortestPathSet[v] &&
                graph[minDistanceVertex][v] &&
                shortestDistances[minDistanceVertex] != INT_MAX &&
                shortestDistances[minDistanceVertex] + graph[minDistanceVertex][v] < shortestDistances[v]
                ) 
            {
                shortestDistances[v] = shortestDistances[minDistanceVertex] + graph[minDistanceVertex][v];
            }
        }
    }

    return shortestDistances;
}

void DisplayShortDistance(int shortestDestances[], Routes *locations){
    int startingLocation = locations->start;
    int destination = locations->destination;
    printf("##############################\n");
    printf("Starting Location: %s \n", nodeNames[startingLocation]);
    printf("Destination: %s \n", nodeNames[destination]);
    printf("Shortest Distance: %d \n\n", shortestDestances[destination]);
}
