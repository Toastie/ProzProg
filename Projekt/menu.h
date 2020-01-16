#ifndef __menu_h__
#define __menu_h__

#include "ausgabe.h"
#include "spiel.h"
#include "einfach.h"

void menuEinfach(){
    char eingabe;

    printEinfach();

    scanf(" %c",&eingabe);

    switch (eingabe){
    case 49:
        spiel(test5);
        break;
    case 50:
        spiel(einfach1);
        break;
    default:
        printf(RED"Falsche Eingabe!\nZum fortfahren ENTER drücken!"RESET);
        while(getchar() != '\n'){};
        getchar();
        break;
    }
}

#endif