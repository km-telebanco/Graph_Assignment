#include <stdio.h>
#include <limits.h>
#include "graph_data.h"

#define VERTEX 5 
char nodeNames[VERTEX][20];

void initializeGraph() {
     for (int i = 0; i < VERTEX; i++) {
        printf("Enter name for Node %c: ", i + 'A');
        scanf("%s", nodeNames[i]);
    }
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
