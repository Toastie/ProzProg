//Sortieralgorithmen
#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>



/* 
* Bubblesort
* Input: zu sortierendes Array, Länge des Arrays
*/
void bubble(int *array, int laenge){
    int temp;
    do{
        for (int i = 1; i < laenge; i++){
            if (array[i] < array[(i - 1)]){
                temp = array[(i - 1)];
                array[(i - 1)] = array[i];
                array[i] = temp;
            }
        }
    }while (laenge--);
    return;
}

/*
* Gibt das Array in der Kommandozeile aus
* Input: Auszugebendes Array und dessen Länge
*/

void printArray(int *array, int laenge){

    printf("Array = {%d",array[0]);
    for (int i = 1; i < laenge; i++){
        printf(", %d",array[i]);
    }
    printf("}\n");
    return;
}

/*
 * Überprüft ob ein Array nicht Leer ist, wobei eine 0 als Leer angesehen wird
 * Input: Zu überprüfendes Array und dessen Länge
 */

int nichtLeer(int *array, int laenge){
    for (int i = 0; i < laenge; i++){
        if(array[i] != 0){
            return 1;
        }
    }
    return 0;
}

/*
* Teilt ein Array in zwei Arrays mit definierte Länge auf
* Input: Zu Teilendes Array, dessen Länge, sowie die beiden Teilarrays und deren Länge
*/

void splitArray(int *array, int laenge, int *links, int laengeL, int *rechts, int laengeR){

        for (int i = 0; i < laengeL; i++){
            links[i] = array[i];
        }
        for (int i = 0; i < laengeR; i++){
            rechts[i] = array[(i + laengeL)];
        }
    return;    
}

/*
* Fügt zwei Arrays zusammen und sortiert dieses dabei der Größe nach aufsteigend (Alle Längen sind bekannt)
* Input: Ziearray und dessen Länge, Teilarrays und dessen Längen
*/

void mergeArray(int *array, int laenge, int *links, int laengeL, int *rechts, int laengeR){
    int i,j;

    //Laufvariable zur bestimmung der aktuellen Position im Zielarray
    int z = 0;

    //Während beide Arrays nicht leer sind werden deren Werte verglichen und Eingefügt
    while (nichtLeer(links,laengeL) && nichtLeer(rechts, laengeR)){
        i = j = 0;

        //Finden des ersten nicht "leeren" elements der entspechenden Arrays
        while (links[i] == 0){
            i++;
        }
        while (rechts[j] == 0){
            j++;
        }

        //Hinzufügen zum Zielarray und entfernen aus dem Teilarray
        //Entspechend der Größe der einzelnen Elemente
        if(links[i] <= rechts[j]){
            array[z] = links[i];
            links[i] = 0;
        }else{
            array[z] = rechts[j];
            rechts[j] = 0;
        }
        
        z++;
    }
    
    //Sobald eines der Teilarrays leer ist werden die restlichen Elemente einfach hinten am Zielarray hinzugefügt

    while (nichtLeer(links,laengeL)){
        i = 0;
        while (links[i] == 0){
            i++;
        }
        array[z] = links[i];
        links[i] = 0;
        z++;
    }

    //Für Rechts eigentlich obsolet da das größere Array immer das Linke ist, zur flexibilität trotzdem implementiert
    while (nichtLeer(rechts,laengeR)){
        j = 0;
        while (rechts[j] == 0){
            j++;
        }
        array[z] = rechts[j];
        rechts[j] = 0;
        z++;
    }

    return;
}

/*
* Mergesort
* Input: ZU sortierendes Array und dessen Länge
*/

void mergeSort(int *array, int laenge){
    int *links, *rechts;
    int laengeL, laengeR;

    //Falls das Array eine Länge von 1 hat kann es nicht weiter Sortiert werden, die Rekusrion bricht ab
    if(laenge == 1){
        return;
    }

    //Bestimmung der Längen der Teilarrays
    if((laenge % 2) == 0){
        laengeL = (laenge / 2);
        laengeR = (laenge / 2);
    }else{
        laengeL = (laenge / 2) + 1;
        laengeR = (laenge / 2);
    }

    //Speicherzuweisung für die Teilarrays
    links = malloc(laengeL * sizeof(int));
    rechts = malloc(laengeR * sizeof(int));

    //Aufteilen des Arrays in die Teilarrays
    splitArray(array,laenge,links,laengeL,rechts,laengeR);

    //Sortieren der Teilarrays
    mergeSort(links,laengeL);
    mergeSort(rechts,laengeR);

    //Geordnetes zusammenfügen der Teilarrays
    mergeArray(array,laenge,links,laengeL,rechts,laengeR);

    //Freigabe des Speichers der Teilarrays
    free(links);
    free(rechts);
}

#endif /* __SORT_H__ */