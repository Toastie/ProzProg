#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main(){
    int auswahl,laenge,z;
    int *array;
    laenge = 0;

    while (1){
    
        //Ausgabe des Menüs
        printf("1) Array-Größe festlegen        4) Bubblesort (Downwards)\n");
        printf("2) Zahlen von Tastatur einlesen 5) Mergesort\n");
        printf("3) Zufallszahlen erzeugen       6) Programm beenden\n");
        printf("Ihre Auswahl:");
        scanf("%d",&auswahl);

        switch(auswahl){
        case 1: //Arraygröße festlegen
            printf("Bitte geben sie die Arraygröße ein:");
            scanf("%d",&laenge);

            array = malloc(laenge * sizeof(int));
            printf("Arraygröße festgelegt!\n");
            printf("---------------------------------------------------------\n");
        break;

        case 2: //Zahlen des Arrays manuell eingeben
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                printf("---------------------------------------------------------\n");
                break;
            }
            
            //Alle Elemente des Arrays werden durchgegangen und ihr Wert manuell abgefragt
            for (int i = 0; i < laenge; i++){
                printf("Wert von array[%d] aus [1,1000]:",i);
                scanf("%d",&z);
                if (z > 1000 || z < 1){
                    i--;
                    printf("Ausserhalb des Wertebereichs\n");
                }else{
                    array[i] = z;
                }
            }
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
        break;
        
        case 3: //Füllen des Arrays mittels Zufallszahlen
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }

            //Zufallszahlen werden in jedes Element des Arrays geschrieben
            for (int i = 0; i < laenge; i++){
                //Als Seed für den Zufallsgenerator wird die aktuelle Zeit plus die Indexnummer des Elements gesetzt
                srand(time(NULL) + i);

                //Um Zahlen zwischen 1 und 1000 zu garantieren wird der Modulo der Zufallszahl und 1000 gebildet und 1 hinzuaddiert
                array[i] = (rand() % 1000 + 1);
            }
            printf("Das Array wurde mit Zufallszahlen gefüllt!\n");
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
            break;

        case 4: //Bubblesort
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }
            printf("Bubblesort:\n");
            bubble(array,laenge);
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
        break;

        case 5: //Mergesort
            if(laenge == 0){
                printf("Bitte legen sie erst die Arraygröße fest!\n");
                break;
            }
            printf("Mergesort:\n");
            mergeSort(array,laenge);
            printArray(array,laenge);
            printf("---------------------------------------------------------\n");
        break;

        case 6: //Programm wird beendet
            free(array);
            return(0);
            printf("---------------------------------------------------------\n");
        break;
            
        default: //Default bei Eingabe eines falschen Wertes
            printf("Falsche Eingabe!\n");
            printf("---------------------------------------------------------\n");
        break;
        }
    }
}
