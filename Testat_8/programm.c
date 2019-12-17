#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

void printArray(int *array,int l){
    printf("Array = {%d",array[0]);
    for (int i = 1; i < l; i++){
        printf(", %d",array[i]);
    }
    printf("}\n");
    return;
}

int main(){
    int auswahl,laenge,z;
    int *array;
    laenge = 0;

    while (1){
    
        printf("1) Array-Größe festlegen        4) Bubblesort (Downwards)\n");
        printf("2) Zahlen von Tastatur einlesen 5) Mergesort\n");
        printf("3) Zufallszahlen erzeugen       6) Programm beenden\n");
        printf("Ihre Auswahl:");
        scanf("%d",&auswahl);

        switch(auswahl){
        case 1:
            printf("Bitte geben sie die Arraygröße ein:");
            scanf("%d",&laenge);

            array = malloc(laenge * sizeof(int));
            printf("Arraygröße festgelegt!\n");
            printf("---------------------------------------------------------\n");
        break;

        case 2:
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                printf("---------------------------------------------------------\n");
                break;
            }

            for (int i = 0; i < laenge; i++){
                printf("Wert von array[%d] aus [1,1000]:",i);
                scanf("%d",&z);
                if (z > 1000 || z < 1){
                    i--;
                    printf("Auserhalb des Wertebereichs\n");
                }else{
                    array[i] = z;
                }
            }
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
        break;
        
        case 3:
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }
            for (int i = 0; i < laenge; i++){
                srand(time(NULL) + i);
                array[i] = (rand() % 1000 + 1);
            }
            printf("Das Array wurde mit Zufallszahlen gefüllt!\n");
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
            break;

        case 4:
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }
            bubble(array,laenge);
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
        break;

        case 5:
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }
            printf("Platzhalter\n");
            for (int i = 0; i < laenge; i++){
                printf("%d\n",array[i]);
            }
            printf("---------------------------------------------------------\n");
        break;

        case 6:
            free(array);
            return(0);
            printf("---------------------------------------------------------\n");
        break;
            
        default:
            printf("Falsche eingabe du Lappen!\n");
            printf("---------------------------------------------------------\n");
        break;
        }
    }
}