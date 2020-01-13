#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "einfach.h"
#include "ausgabe.h"


int main(){
    char eingabe;

    printf("test");
    getchar();

    while(1){
        system("clear");
        printMenu();
        scanf(" %1c",&eingabe);

        switch (eingabe){
        case 49: 
            printf("Platzhalter für einfach!");
            getchar();
        break;
        case 50:
            printf("Platzhalzter für Mittel!");
            getchar();
        break;
        case 51:
            printf("Platzhalter für Schwer!");
        break;
        case 52:
            printf("Platzhalter für Anleitung!");
            getchar();
        break;
        case 53:
            return(0);
        break;
        default:
            printf("Falsche Eingabe!\nZum fortfahren ENTER drücken!\n");
            while(getchar() != '\n'){};
            getchar();            
        break;
        }
        while (getchar() != '\n'){}
    }
    return(0);
}