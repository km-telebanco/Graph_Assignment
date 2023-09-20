#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"
#include "graph.h"

int main(){
    char startinglocation, destination;
  
    do
    {
       DisplayMenu();
       menuSelection = selectMenu();
       switch(menuSelection){
        case 1: 
            initializeGraph();
            break;
        case 2:
            startinglocation = EnterStartingLocation();
            break;
        case 3:
            destination = EnterDestination();
            break;
        case 4: 
            int start = 0;
            int dest = 4;
            int *shortestDestances = EvaluateShortDistance(graph, start, dest);
            DisplayShortDistance(shortestDestances, start, dest);
            break;
        case 5:
            displayGraph();
            break;
        default:
            break;
       }
    } while (menuSelection != EXITCODE);

    return 0;
}
