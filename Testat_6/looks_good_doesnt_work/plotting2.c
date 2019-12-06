#include <stdlib.h>
#include <stdio.h>
#include "./libBMP.h"
#include <math.h>

int xMax, xMin, yMax, yMin;

uint32_t toBMP(double xMath, double yMath, int w, int h){     //Mathematische Koordinaten in Array Koordinate umwandeln
    int x,y;

    x = (xMath - xMin) * (w / (xMax - xMin));
    y = (yMath - yMin) * (h / (yMax - yMin));

    return((w * y) + x);
}

double xToMath(int x, int w, int h){
    return(xMin + ((x * (xMax - xMin)) / w));
}

int main(){
    int w,h,x,y,koordinate;
    double schritt;
    uint32_t *array;

    w = h = 300;
    x = y = 0;
    xMax = 100;
    yMax = 100;
    xMin = -xMax;
    yMin = -yMax;

    array = malloc((w * h) * sizeof(uint32_t));

    for (int i = 0; i < (w * h); i++){
        array[i] = COLOR_WHITE;
    }

    for (uint16_t i = toBMP(xMin,0,w,h); i <= toBMP(xMax,0,w,h); i++){
        array[i] = COLOR_RED;
    }

    for (uint16_t i = toBMP(0,yMax,w,h); i < toBMP(0,yMin,w,h); i += w){
        array[i] = COLOR_RED;
    }
    
    /*
    for (int i = 0; i < h; i++){
        array[(i * h + (w / 2))] = COLOR_RED;
    }
    */

/*
    for (int i = 0 ; i < w + 1; i++){
        int a,b;
        a = xToMath(i,w,h);
        b = sin(a);
        array[toBMP(a,b,w,h)] = COLOR_BLACK;
    }
    */
    
    

    koordinate = w * y + x;
    array[koordinate] = COLOR_RED;
    array[toBMP(x,y,w,h)] = COLOR_BLUE;

    bmp_create("./plotting2.bmp",array,w,h);

    free(array);
}