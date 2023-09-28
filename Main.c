#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
#include "graph.h"

int main(){
    int *shortestDistances;
    Routes *route;
    route = (Routes *)malloc(sizeof(Routes));

    do
    {
       DisplayMenu();
       menuSelection = SelectMenu();
       switch(menuSelection){
        case 1: 
            AssignNodeNames();
            break;
        case 2:
            DisplayCurrentLocations(nodeNames);
            route->start = EnterStartingLocation();
            break;
        case 3:
            DisplayCurrentLocations(nodeNames);
            route->destination = EnterDestination();
            break;
        case 4: 
            shortestDistances = EvaluateShortDistance(graph, route);
            DisplayShortDistance(shortestDistances, route);
            break;
        case 5:
            DisplayGraph();
            break;
        default:
            break;
       }
    } while (menuSelection != EXITCODE);

    return 0;
}
