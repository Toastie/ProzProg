#ifndef __spiel_h__
#define __spiel_h__

#include "ausgabe.h"
#include "einfach.h"
#include "mittel.h"
#include "schwer.h"

int nichtGeloest(struct nono x){
    int a = 5 * x.schwierigkeit;

    for (int i = 0; i < a; i++){
        for (int j = 0; j < a; j++){
            if(x.loesung[i][j] == 1 && x.array[i][j] == 0 || x.loesung[i][j] == 0 && x.array[i][j] == 1) {
                return(1);
            }
        }        
    }
    return(0);
}

void spiel(struct nono x){
    int a = 5 * x.schwierigkeit;
    int z, s;
    char e;
    
    system("clear");
    printTest(x);

    while (nichtGeloest(x)){

        printf("Eingabe (Zeile, Spalte, Eingabe: ):");
        scanf(" %d %d %c",&z,&s,&e);
        while(getchar() != '\n');

        if(e == 's') {
            return;
        }

        if(e != 'x' && e != 'o' && e != '-' && e != '?'){
            printf(RED"Falsche Eingabe!\n"RESET);
        }else if(z > a || s > a || z < 0 || s < 0){
            printf(RED"Falsche Zeilen / Spalten Eingabe!\n"RESET);
        }else{
            if(e == 'x') {
                e = 1;
            }
            else if(e == 'o') {
                e = 2;
            }
            else if(e == '?') {
                e = x.loesung[(z - 1)][(s - 1)];
                if(e == 0) {
                    e = 2;
                }
            }
            else {
                e = 0;
            }
            x.array[(z - 1)][(s - 1)] = e;
            system("clear");
            printTest(x);
        }
    }

    printWin();
    getchar();
    return;
}

#endif