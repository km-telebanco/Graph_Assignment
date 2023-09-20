#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define VERTEX 5 

int graph[VERTEX][VERTEX];
char nodeNames[VERTEX][20];

void initializeGraph() {
    for (int i = 0; i < VERTEX; i++) {
        printf("Enter name for Node %c: ", i + 'A');
        scanf("%s", nodeNames[i]);
    }

    for (int i = 0; i < VERTEX; i++) {
        for (int j = 0; j < VERTEX; j++) {
            graph[i][j] = INT_MAX;
        }
    }

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

void displayGraph() {
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

int* EvaluateShortDistance(int graph[][VERTEX], int startinglocation, int destination){
    static int shortestDistances[VERTEX];
    bool shortestPathSet[VERTEX];

    for (int i = 0; i < VERTEX; i++) {
        shortestDistances[i] = INT_MAX;
        shortestPathSet[i] = false;
    }

    shortestDistances[startinglocation] = 0;

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

void DisplayShortDistance(int shortestDestances[], int startingLocation, int destination){
    printf("##############################\n");
    printf("Starting Location: %s \n", nodeNames[startingLocation]);
    printf("Destination: %s \n", nodeNames[destination]);
    printf("Shortest Distance: %d \n\n", shortestDestances[destination]);
}
