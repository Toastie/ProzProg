#include <stdint.h>
#include <stdio.h>

#define WIDTH 300
#define HEIGHT 300
#define XMAX 100
#define XMIN -100
#define YMAX 100
#define YMIN -100

// Umrechnung von BMP in Mathematische Koordinaten
void toMath(uint32_t xBmp, uint32_t yBmp, double *xMath, double *yMath){
    *xMath = XMIN + ((xBmp * (XMAX - XMIN))/WIDTH);
    *yMath = YMIN + ((yBmp * (YMAX - YMIN))/HEIGHT);
}

//Umrechnung von Mathematischen im BMP Koordinate
void toBmp(double xMath, double yMath, uint32_t *xBmp, uint32_t *yBmp){
    *xBmp = (xMath - XMIN) * ((double)WIDTH / ((double)XMAX - (double)XMIN));
    *yBmp = HEIGHT - ((yMath - YMIN) * ((double)HEIGHT / ((double)YMAX - (double)YMIN)));
}

int main(){
    uint32_t xBmp,yBmp;
    double xMath,yMath;

    xBmp = yBmp = 0;

    xMath = 2;
    yMath = 1;

    toBmp(xMath,yMath,&xBmp,&yBmp);
    toMath(xBmp,yBmp,&xMath,&yMath);

    printf("%lf %lf\n",xMath,yMath);
}