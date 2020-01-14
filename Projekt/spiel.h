#ifndef __spiel_h__
#define __spiel_h__

#include "ausgabe.h"
#include "einfach.h"

int nichtGeloest(struct einfach x){
    int a = 5 * x.schwierigkeit;

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if(x.loesung[i][j] != x.array[i][j] && x.array[i][j] != 2){
                return(1);
            }
            if(x.array[i][j] == 2 && x.loesung[i][j] != 0){
                return(1);
            }
        }        
    }
    return(0);
}

void spiel(struct einfach x){
    int a = 5 * x.schwierigkeit;
    int z,s,e;

    while (nichtGeloest(x)){
        printTest(x);

        printf("Eingabe:");
        scanf(" %d %d %d",&z,&s,&e);

        x.array[(z - 1)][(s - 1)] = e;
    }
    
    printTest(x);
    getchar();
    return;
}

#endif