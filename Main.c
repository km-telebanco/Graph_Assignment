#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "functions.h"

int main(){

      do
    {
       DisplayMenu();
       menuSelection = selectMenu();
       switch(menuSelection){
        case 1: 
            // AssignNodeName()
            break;
        case 2:
            // EnterStartingLocation()
            break;
        case 3:
            // EnterDestination()
            break;
        case 4: 
            // EvaluateShortDistance();
            // DisplayShortDistance();
            break;
        default:
            break;
       }
    } while (menuSelection != EXITCODE);

    return 0;
}