#include <stdio.h>
#define EXITCODE 5

int AskNodeToInsert();
int menuSelection;

void DisplayMenu()
{

    printf("[1] Assign Names To Nodes\n");
    printf("[2] Starting Location\n");
    printf("[3] Destination\n");
    printf("[4] Shortest Distance\n");
    printf("[5] Exit\n");
}

int selectMenu()
{
    int choice;
    printf("Choose Graph Selection: ");
    scanf("%d", &choice);
    return choice;
}
