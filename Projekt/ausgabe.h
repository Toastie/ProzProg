#ifndef __ausgabe_h__
#define __ausgabe_h__

#include "einfach.h"
#include <stdio.h>
#include <stdlib.h>

void printMenu(){
    printf("\n\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|               Nonogramm               |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|   1. Einfach           2. Mittel      |\n");
    printf("|   3. Schwer            4. Anleitung   |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
}


void printE(struct einfach x, int array[5][5]){

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(array[i][j] == 1){
                printf("|x");
            }else{
                printf("| ");
            }
        }
        printf("|\n");
    }
    return;
}


#endif