#include <stdio.h>
#include <limits.h>
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
