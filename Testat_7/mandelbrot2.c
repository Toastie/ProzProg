#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libBMP.h"
#include <complex.h>
#include <math.h>

#define YMAX 1
#define YMIN -1
#define XMAX 1
#define XMIN -2

//Rechnet BMP Koordinaten in mathematische Koordinaten um
void toMath(uint32_t xBmp, uint32_t yBmp, double *xMath, double *yMath,int width,int height){
    *xMath = (double)XMIN + (((double)xBmp * ((double)XMAX - (double)XMIN))/(double)width);
    *yMath = (-1) * ((double)YMIN + (((double)yBmp * ((double)YMAX - (double)YMIN))/(double)height));
}

//Ersetzt die im Array eingetragenen Rekursionsanzahl durch entsprechende Farben
void buildArray(uint32_t *array,int width, int height,uint32_t nmax){
    int schritt;
    schritt = nmax / 5;
    for (uint32_t i = 0; i < (width * height); i++){
        if (array[i] == nmax){
            array[i] = COLOR_BLACK;
        }else if(array[i] < (nmax / schritt)){
            array[i] = COLOR_WHITE;
        }else if(array[i] < (2 * (nmax / schritt))){
            array[i] = COLOR_GREEN;
        }else if(array[i] < (3 * (nmax / schritt))){
            array[i] = COLOR_ORANGE;
        }else if(array[i] < (4 * (nmax / schritt))){
            array[i] = COLOR_RED;
        }else{
            array[i] = COLOR_BLUE;
        }
    }
    

    printf("build array successfull\n");
}

//Rekursive berechnung der Folge
void mandelbrot(uint32_t xBMP,uint32_t yBMP,uint32_t *array,double complex z,int width, int height,uint32_t nmax){
    double betrag,xR,yI;
    double complex c;
    int bmp;

    //Berechnung des Speicherortes im Array
    bmp = (yBMP * width) + xBMP;

    //Falls die Rekursionsanzahl nmax entspricht wird abgebrochen und die Folge als teil der Mandelbrotmenge behandelt
    if(array[bmp] == nmax){
        return;
    }

    //Umrechnung in mathematische Koordinaten
    toMath(xBMP,yBMP,&xR,&yI,width,height);

    //Bildung des Betrages von Zn
    betrag = sqrt(( (creal(z)*creal(z)) + (cimag(z) * cimag(z)) ));
    
    //Test ob der Betrag größer 2 ist, falls ja wird abgebrochen und die Folge ist nicht Teil der Mandelbrotmenge
    if (betrag >= 2){
        return;
    }
    
    //Berechnung der komplexen Zahl C
    c = xR + yI * I;

    //Erhöhung des Rekursionscounters um einen
    array[bmp] += 1;

    //Aufruf der Funktion mit neuem Z
    mandelbrot(xBMP,yBMP,array,((z * z) + c),width,height,nmax);

    return;
}

int main(){
    uint32_t *array;
    uint32_t nmax;
    int width, height;

    //Abfrage der Parameter
    printf("(3)Breite:");
    scanf("%d",&width);
    printf("(2)Höhe:");
    scanf("%d",&height);
    printf("(5)Rekursionstiefe:");
    scanf("%u",&nmax);

    array = malloc((width * height) * sizeof(uint32_t));
    
    //Jede BMP Koordinate wird durchlaufen und es wird für sie bestimmt ob sie Teil der Mandelbrotmenge ist
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            mandelbrot(j,i,array,0,width,height,nmax);
        }
    }

    //Bau des arrays, also Umwandlung von Rekursionstiefe in entsprechende Farben
    buildArray(array,width,height,nmax);


    //Erstellen der .bmp Datei
    bmp_create("./mandelbrot2.bmp",array,width,height);

    free(array);
    return(0);
}