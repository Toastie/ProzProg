#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./libBMP.h"

#define WIDTH 600
#define HEIGHT 1200
#define XMAX 5
#define XMIN -5

//Die YMIN / YMAX Werte müssen anhand der Funktion angepasst werden, damit keine y werte ausgereichnet werden die außerhalb des Bereiches liegen!
#define YMAX 125
#define YMIN -125

// Umrechnung von BMP in Mathematische Koordinaten
void toMath(uint32_t xBmp, uint32_t yBmp, double *xMath, double *yMath){
    *xMath = XMIN + ((xBmp * (XMAX - XMIN))/WIDTH);
    *yMath = YMIN + ((yBmp * (YMAX - YMIN))/HEIGHT);
}

//Umrechnung von Mathematischen im BMP Koordinate
void toBmp(double xMath, double yMath, uint32_t *xBmp, uint32_t *yBmp){
    *xBmp = (xMath - XMIN) * ((double)WIDTH / ((double)XMAX - (double)XMIN));

    //Da die BMP und Mathematische Y Achse entgegengesetzt sind wird die BMP koordinate von unten aus gesehen berechnet.
    //Um diesem entgegenzuwirken wird der Wert von der Höhe abgezogen um ihn von oben aus gesehen zu erhalten
    *yBmp = HEIGHT - ((yMath - YMIN) * ((double)HEIGHT / ((double)YMAX - (double)YMIN)));
}

//Bau des Arrays, einfügen des weißen Hintergrunds und einfügen der Achsen
void buildArray(uint32_t *array){
    uint32_t x,y,bmp;
    x = y = bmp = 0;

    //Weißer Hintergrund wird ins Array eingetragen
    for (uint32_t i = 0; i < (WIDTH * HEIGHT); i++){
        array[i] = COLOR_WHITE;
    }

    //Berechnen der Koordinaten des X Achsen anfangs
    toBmp(XMIN, 0, &x, &y);

    //Umwandlung der BMP Koordinate in die entsprechende Arrayadresse
    bmp = (y * WIDTH) + x;

    //Eintragung der X Achse
    for (uint32_t i = bmp; i < (bmp + WIDTH); i++){
        array[i] = COLOR_RED;
    }

    //Berechnen des Y Achsen anfangs
    toBmp(0,YMAX,&x,&y);

    //Umwandlung in Array Adresse
    bmp = (y * WIDTH) + x;

    //Eintragung der Y Achse
    for (int i = 0; i < HEIGHT; i++){
        //Ein roter Pixel pro Reihe, also Koordinate der Y Achse + Breite des Bildes
        //ergibt die Koordinate der nächsten Zeile.
        array[bmp + (i * WIDTH)] = COLOR_RED;
    }
    
    
}

//Trägt mathematische Koordinaten in das Array ein
void eintagen(double xMath, double yMath, uint32_t *array){
    uint32_t bmp,x,y;

    //Umwandelung in BMP Koordinaten
    toBmp(xMath,yMath,&x,&y);

    //Umwandlung der BMP Koordinaten in die entsprechende Arrayposition
    bmp = (y * WIDTH) + x;

    //Adresse wird der Wert für Schwarz zugewiesen
    array[bmp] = COLOR_BLACK;
}

int main(){
    uint32_t *array;
    double schritt,yMath;

    //Berechnung der Schrittgröße um jede BMP X Koordinate abzudecken
    schritt = (double)1/((double)WIDTH/((double)XMAX + (double)abs(XMIN)));

    //Zuweisung des Speichers
    array = malloc((WIDTH * HEIGHT) * sizeof(uint32_t));

    //Bau des Arrays (Hintergund & Achsen)
    buildArray(array);

    //Ausrechnen der Mathematischen Koordinaten der einzutragenen Funktion, wobei i = x ist 
    for (double i = XMIN; i <= XMAX; i += schritt){

        //Zurzeit f(x) = x^3
        yMath = i*i*i;
        
        //Funktionswerte in das Array eintragen
        eintagen(i,yMath,array);
    }
    
    //Erstellen der .bmp Datei
    bmp_create("./plotting.bmp",array,WIDTH,HEIGHT);

    //Freigabe des Arrayspeichers
    free(array);
    return(0);
}