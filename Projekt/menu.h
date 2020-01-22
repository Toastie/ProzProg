#ifndef __menu_h__
#define __menu_h__

#include "ausgabe.h"
#include "spiel.h"

void menuEinfach(){
    int eingabe;

    printEinfach();

    while (getchar() != '\n'){}
    scanf(" %d",&eingabe);

    switch (eingabe){
    case 1:
        spiel(einfach1);
        break;
    case 2:
        spiel(einfach2);
        break;
    case 3:
        spiel(einfach3);
        break;
    case 4:
        spiel(einfach4);
        break;
    case 5:
        spiel(einfach5);
        break;
    case 6:
        spiel(einfach6);
        break;
    case 7:
        spiel(einfach7);
        break;
    case 8:
        spiel(einfach8);
        break;
    case 9:
        spiel(einfach9);
        break;
    case 10:
        spiel(einfach10);
        break;
    default:
        printf(RED"Falsche Eingabe!\nZum fortfahren ENTER drücken!"RESET);
        while(getchar() != '\n'){};
        getchar();
        break;
    }
}

void menuMittel(){
    int eingabe;

    printMittel();

    while (getchar() != '\n'){}
    scanf(" %d",&eingabe);

    switch (eingabe){
    case 1:
        spiel(mittel1);
        break;
    case 2:
        spiel(mittel2);
        break;
    case 3:
        spiel(mittel3);
        break;
    case 4:
        spiel(mittel4);
        break;
    case 5:
        spiel(mittel5);
        break;
    case 6:
        spiel(mittel6);
        break;
    case 7:
        spiel(mittel7);
        break;
    case 8:
        spiel(mittel8);
        break;
    case 9:
        spiel(mittel9);
        break;
    case 10:
        spiel(mittel10);
        break;
    default:
        printf(RED"Falsche Eingabe!\nZum fortfahren ENTER drücken!"RESET);
        while(getchar() != '\n'){};
        getchar();
        break;
    }
}

void menuSchwer(){
    int eingabe;

    printSchwer();

    while (getchar() != '\n'){}
    scanf(" %d",&eingabe);

    switch (eingabe){
    case 1:
        spiel(schwer1);
        break;
    case 2:
        spiel(schwer2);
        break;
    case 3:
        spiel(schwer3);
        break;
    case 4:
        spiel(schwer4);
        break;
    case 5:
        spiel(schwer5);
        break;
    case 6:
        spiel(schwer6);
        break;
    case 7:
        spiel(schwer7);
        break;
    case 8:
        spiel(schwer8);
        break;
    case 9:
        spiel(schwer9);
        break;
    case 10:
        spiel(schwer10);
        break;
    default:
        printf(RED"Falsche Eingabe!\nZum fortfahren ENTER drücken!"RESET);
        while(getchar() != '\n'){};
        getchar();
        break;
    }
}

#endif