#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libBMP.h"
#include <complex.h>
#include <math.h>

#define WIDTH 3000
#define HEIGHT 2000
#define YMAX 1
#define YMIN -1
#define XMAX 1
#define XMIN -2
#define NMAX 100

void toMath(uint32_t xBmp, uint32_t yBmp, double *xMath, double *yMath){
    *xMath = (double)XMIN + (((double)xBmp * ((double)XMAX - (double)XMIN))/(double)WIDTH);
    *yMath = (-1) * ((double)YMIN + (((double)yBmp * ((double)YMAX - (double)YMIN))/(double)HEIGHT));
}

void buildArray(uint32_t *array){
    for (int i = 0; i < (WIDTH * HEIGHT); i++){
        array[i] = COLOR_WHITE;
    }

    printf("build array successfull\n");
}

int mandelbrot(double xR,double yI,int tiefe,double complex z){
    double betrag;
    double complex c;

    if(tiefe == NMAX){
        return(0);
    }

    betrag = sqrt(( (creal(z)*creal(z)) + (cimag(z) * cimag(z)) ));
    
    if (betrag >= 2){
        return(tiefe);
    }
    
    c = xR + yI * I;

    return(mandelbrot(xR,yI,(tiefe + 1),((z * z) + c)));
}

int main(){
    uint32_t *array;
    double x,y;
    x = y = 0;

    array = malloc((WIDTH * HEIGHT) * sizeof(uint32_t));

    buildArray(array);
    
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            //printf("%d %d\n",i,j);
            toMath(j,i,&x,&y);

            switch (mandelbrot(x,y,1,0)){
            case 1: array[((i * WIDTH) + j)] = COLOR_WHITE; break;
            case 2: array[((i * WIDTH) + j)] = COLOR_GREEN; break;
            case 3: array[((i * WIDTH) + j)] = COLOR_ORANGE; break;
            case 4: array[((i * WIDTH) + j)] = COLOR_RED; break;
            case 5: array[((i * WIDTH) + j)] = COLOR_BLUE; break;
            case 0: array[((i * WIDTH) + j)] = COLOR_BLACK; break;
            }
            
        }
    }

   /*
   for (int i = 0; i < (WIDTH * HEIGHT); i++){
       array[i] = COLOR_PINK;
   }
   */
    
    bmp_create("./mandelbrot.bmp",array,WIDTH,HEIGHT);

   //free(array);
    return(0);
}