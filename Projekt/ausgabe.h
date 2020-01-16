#ifndef __ausgabe_h__
#define __ausgabe_h__

#include "einfach.h"
#include <stdio.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define UNDER "\e[4m"
#define BOLD "\e[1m"

void printMenu(){
    printf(RESET);
    system("clear");
    printf("\n\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|               Nonogramm               |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|   1. Einfach            2. Mittel     |\n");
    printf("|   3. Schwer             4. Anleitung  |\n");
    printf("|              "RED"5. Beenden"RESET"               |\n");
    printf("+---------------------------------------+\n");
}

void printEinfach(){
    printf(RESET);
    system("clear");

    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|                Einfach                |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|   1.                   2.             |\n");
    printf("|   3.                   4.             |\n");
    printf("|   5.                   6.             |\n");
    printf("|   7.                   8.             |\n");
    printf("|   9.                   10.            |\n");
    printf("|               "RED"z: Zurück"RESET"               |\n");
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

    //Ausgabe der Anzahl der Kreuze in den Spalten
    for (int i = 0; i < ((a / 2) + 1); i++){
        if(zeileNichtLeer(x,i)){
            for(int r = 0; r < (a /2) + 1; r++){
                if(spalteNichtLeer(x,r)){
                    printf("  ");
                }
            }
            if(i == (a / 2)){
                printf(UNDER);
            }
            for (int j = 0; j < a; j++){
                if(j % 5 == 0){
                    printf(RED "|" RESET);
                    if(i == (a / 2)){
                        printf(UNDER);
                    }
                }else{
                    printf("|");
                }
                if(x.spalten[i][j] != 0){
                    printf("%d",x.spalten[i][j]);
                }else {
                    printf(" ");
                }
            }
            printf(RED "|\n" RESET);
        }
    }

    //Ausgabe der Anzahl der Kreuze in den Zeilen
    for (int i = 0; i < a; i++){
        for (int r = 0; r < (a /2) + 1; r++){
            if(spalteNichtLeer(x,r)){
                printf("|%d",x.zeilen[i][r]);
            }
        }
        if((i + 1) % 5 == 0){
            printf(UNDER);
        }
        for (int j = 0; j < a; j++){
            if(j % 5 == 0){
                printf(RED "|" RESET);
                if((i + 1) % 5 == 0){
                    printf(UNDER);
                }
            }else{
                printf("|");
            }
            
            if(x.array[i][j] == 1){
                printf("x");
            }else if(x.array[i][j] == 2){
                printf(GRN"o"RESET);
                if((i + 1) % 5 == 0){
                    printf(UNDER);
                }
            }else{
                printf(" ");
            }
        }
        printf(RED "|\n" RESET);
    }

    printf(RESET);
    return;
}

void printWin(){

    printf(RESET"\n\n");

    printf(GRN);

    printf("  /$$$$$$                                               /$$             /$$           /$$    /$$                           /$$\n");
    printf(" /$$__  $$                                             | $$            | $$          | $$   |__/                          | $$\n");
    printf("| $$  \\__/ /$$$$$$ /$$$$$$$  /$$$$$$  /$$$$$$ /$$$$$$ /$$$$$$  /$$   /$| $$ /$$$$$$ /$$$$$$  /$$ /$$$$$$ /$$$$$$$  /$$$$$$| $$\n");
    printf("| $$      /$$__  $| $$__  $$/$$__  $$/$$__  $|____  $|_  $$_/ | $$  | $| $$|____  $|_  $$_/ | $$/$$__  $| $$__  $$/$$_____| $$\n");
    printf("| $$     | $$  \\ $| $$  \\ $| $$  \\ $| $$  \\__//$$$$$$$ | $$   | $$  | $| $$ /$$$$$$$ | $$   | $| $$  \\ $| $$  \\ $|  $$$$$$|__/\n");
    printf("| $$    $| $$  | $| $$  | $| $$  | $| $$     /$$__  $$ | $$ /$| $$  | $| $$/$$__  $$ | $$ /$| $| $$  | $| $$  | $$\\____  $$   \n");
    printf("|  $$$$$$|  $$$$$$| $$  | $|  $$$$$$| $$    |  $$$$$$$ |  $$$$|  $$$$$$| $|  $$$$$$$ |  $$$$| $|  $$$$$$| $$  | $$/$$$$$$$//$$\n");
    printf(" \\______/ \\______/|__/  |__/\\____  $|__/     \\_______/  \\___/  \\______/|__/\\_______/  \\___/ |__/\\______/|__/  |__|_______/|__/\n");
    printf("                            /$$  \\ $$                                                                                         \n");
    printf("                           |  $$$$$$/                                                                                         \n");
    printf("                            \\______/                                                                                          \n");
    printf("                   /$$     /$$               /$$                                                      /$$                     \n");
    printf("                  |  $$   /$$/              | $/                                                     | $$                     \n");
    printf("                   \\  $$ /$$/$$$$$$ /$$   /$|_/$$    /$$/$$$$$$        /$$  /$$  /$$ /$$$$$$ /$$$$$$$| $$                     \n");
    printf("                    \\  $$$$/$$__  $| $$  | $$|  $$  /$$/$$__  $$      | $$ | $$ | $$/$$__  $| $$__  $| $$                     \n");
    printf("                     \\  $$| $$  \\ $| $$  | $$ \\  $$/$$| $$$$$$$$      | $$ | $$ | $| $$  \\ $| $$  \\ $|__/                     \n");
    printf("                      | $$| $$  | $| $$  | $$  \\  $$$/| $$_____/      | $$ | $$ | $| $$  | $| $$  | $$                        \n");
    printf("                      | $$|  $$$$$$|  $$$$$$/   \\  $/ |  $$$$$$$      |  $$$$$/$$$$|  $$$$$$| $$  | $$/$$                     \n");
    printf("                      |__/ \\______/ \\______/     \\_/   \\_______/       \\_____/\\___/ \\______/|__/  |__|__/                     \n");
    printf(RESET);
}

#endif