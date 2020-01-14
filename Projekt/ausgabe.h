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

int zeileNichtLeer(struct einfach x, int z){
    int a = 5 * x.schwierigkeit;

    for (int i = 0; i < a; i++){
        if(x.spalten[z][i] != 0){
            return(1);
        }
    }
    return(0);
}

int spalteNichtLeer(struct einfach x, int s){
    int a = 5 * x.schwierigkeit;

    for (int i = 0; i < a; i++){
        if(x.zeilen[i][s] != 0){
            return(1);
        }
    }
    return(0);
}

void printTest(struct einfach x){
    int a = 5 * x.schwierigkeit;
    system("clear");

    //Ausgabe der Anzahl der Kreuze in den Spalten
    for (int i = 0; i < ((a / 2) + 1); i++){
        if(zeileNichtLeer(x,i)){
            for(int r = 0; r < (a /2) + 1; r++){
                if(spalteNichtLeer(x,r)){
                    printf("  ");
                }
            }
            for (int j = 0; j < a; j++){
                if(j % 5 == 0){
                    printf("|");
                }
                if(x.spalten[i][j] != 0){
                    printf("|%d",x.spalten[i][j]);
                }else {
                    printf("| ");
                }
            }
            printf("|\n");
        }
    }

    //Ausgabe des Trennstrich       Muss noch überarbeitet werden

    for(int r = 0; r < (a /2) + 1; r++){
        if(spalteNichtLeer(x,r)){
            printf("  ");
        }
    }
    
    for (int i = 0; i < (a * 2) + 3; i++){
        printf("-");
    }
    
    printf("\n");
    
    //Ausgabe der Anzahl der Kreuze in den Zeilen
    for (int i = 0; i < a; i++){
        for (int r = 0; r < (a /2) + 1; r++){
            if(spalteNichtLeer(x,r)){
                printf("|%d",x.zeilen[i][r]);
            }
        }

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