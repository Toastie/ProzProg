#include <stdio.h>
#include <stdlib.h>

#include "einfach.h"
#include "ausgabe.h"
#include "spiel.h"

/*
int nichtGeloestE(int a[5][5], int b[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (a[i][j] != b[i][j]){
                return(1);
            }
        }
    }
    return(0);
}

void einfach(struct einfach x){
    int r[5][5];
    int z,s,e;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            r[i][j] = 0;
        }
    }

    while (nichtGeloestE(x.loesung,r)){
        printE(x,r);

        printf("Eingabe:");
        scanf("%d %d %d",&z,&s,&e);

        r[(z - 1)][(s - 1)] = e;
    }
    
    printE(x,r);
}

*/

int main(){
    char eingabe;

    printf("test");
    getchar();

    while(1){
        system("clear");    
        printMenu();
        scanf(" %1c",&eingabe);

        switch (eingabe)
        {
        case 49:
            spiel(test5);
            break;
        case 50:
            spiel(test10);
            break;
        case 51:
            printf("Platzhalter für Schwer!");
            break;
        case 52:
            printf("Platzhalter für Anleitung!");
            getchar();
            break;
        case 53:
            return (0);
            break;
        default:
            printf("Falsche Eingabe!\nZum fortfahren ENTER drücken!\n");
            while (getchar() != '\n'){};
            getchar();
            break;
        }
        while (getchar() != '\n'){}
    }
    return(0);
}