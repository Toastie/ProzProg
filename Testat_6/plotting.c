#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./libBMP.h"

#define WIDTH 600
#define HEIGHT 1200
#define XMAX 5
#define XMIN -5
#define YMAX 125
#define YMIN -125

//Umrechnung von Mathematischen im BMP Koordinate
void toBmp(double xMath, double yMath, uint32_t *xBmp, uint32_t *yBmp){
    *xBmp = (xMath - XMIN) * ((double)WIDTH / ((double)XMAX - (double)XMIN));
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

    //Umwandlung in Array Adresse
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
        //Ein roter Pixel pro reihe, also Koordinate der Y Achse + breite des Bildes
        //ergibt die Koordinate der nächsten Zeile.
        array[bmp + (i * WIDTH)] = COLOR_RED;
    }
    
    
}

//Trägt mathematische Koordinaten in das Array ein
void eintagen(double xMath, double yMath, uint32_t *array){
    uint32_t bmp,x,y;

    toBmp(xMath,yMath,&x,&y);

    bmp = (y * WIDTH) + x;

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


    for (double i = XMIN; i <= XMAX; i += schritt){
        yMath = i*i*i;
        eintagen(i,yMath,array);
    }
    
    bmp_create("./plotting.bmp",array,WIDTH,HEIGHT);

    free(array);
    return(0);
}