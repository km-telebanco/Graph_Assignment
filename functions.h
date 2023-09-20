#include <stdio.h>
#define EXITCODE 6

int AskNodeToInsert();
int menuSelection;

void DisplayMenu()
{

    printf("[1] Assign Names To Nodes\n");
    printf("[2] Starting Location\n");
    printf("[3] Destination\n");
    printf("[4] Shortest Distance\n");
    printf("[5] Dispay Graph\n");
    printf("[6] Exit\n");
}

int selectMenu()
{
    int choice;
    printf("Choose Graph Selection: ");
    scanf("%d", &choice);
    return choice;
}

char EnterStartingLocation(){
    char startNode;
    printf("Enter Starting Location: ");
    scanf(" %c", &startNode);

    return startNode;
}

char EnterDestination(){
    char endNode;
    printf("Enter Destination: ");
    scanf(" %c", &endNode);

    return endNode;
}
