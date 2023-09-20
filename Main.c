#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h" //non-related sa graph functions +cohesiveness
#include "graph.h" //graph related functions

int main(){
    int *shortestDistances; // array
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
