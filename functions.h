#include <stdio.h>
#define EXITCODE 6
#define VERTEX 5

int menuSelection;

void DisplayMenu()
{
    printf("\n[1] Assign Names To Nodes\n");
    printf("[2] Starting Location\n");
    printf("[3] Destination\n");
    printf("[4] Shortest Distance\n");
    printf("[5] Display Graph\n");
    printf("[6] Exit\n");
}

int SelectMenu()
{
    int choice;
    printf("\nChoose Graph Selection: ");
    scanf("%d", &choice);
    return choice;
}

void DisplayCurrentLocations(char nodeNames[VERTEX][20])
{
    for(int i = 0; i < VERTEX; i++)
    {
        printf("[%d] %s \n", i + 1, nodeNames[i]);
    }
}

int EnterStartingLocation(){
    int start;
    printf("Enter Starting Location: ");
    scanf("%d", &start);

    return start - 1;
}

int EnterDestination(){
    int destination;
    printf("Enter Destination: ");
    scanf("%d", &destination);

    return destination - 1;
}
