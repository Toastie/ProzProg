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
    printf("|   1. Einfach            2. Mittel     |\n");
    printf("|   3. Schwer             4. Anleitung  |\n");
    printf("|              5. Beenden               |\n");
    printf("+---------------------------------------+\n");
}

/*
void printE(struct einfach x, int array[5][5]){
    system("clear");
    
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
*/

void printTest(struct einfach x){
    int a = 5 * x.schwierigkeit;
    system("clear");

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if(j % 5 == 0){
                printf("|");
            }
            if(x.array[i][j] == 1){
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