#include <stdio.h>
#include <stdlib.h>

#include "einfach.h"
#include "ausgabe.h"
#include "spiel.h"
#include "menu.h"


int main(){
    char eingabe;

    while(1){
        printf(RESET);
        system("clear");    
        printMenu();
        scanf(" %1c",&eingabe);

        switch (eingabe)
        {
        case 49:
            spiel(test5);
            //menuEinfach();
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
            system("clear");
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