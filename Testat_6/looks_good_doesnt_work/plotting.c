#include <stdio.h>
#include "./libBMP.h"

int w = 300;
int h = 300; 
int xMax,xMin,yMax,yMin;

int * toMath(int x, int y){
    static int array[2];

    array[0] = xMin + ((x * (xMax - xMin)) / w);
    array[1] = yMin + ((y * (yMax - yMin)) / h);

    return(array);
}

int main(){
    int x,y;
    int *p;
    uint32_t *array;

    /*
    printf("Höhe:");
    scanf("%d",&h);
    printf("Breite:");
    scanf("%d",&w);
    */

    array = malloc((w * h) * sizeof(uint32_t));

    for (int i = 0; i < (w * h); i++){
        array[i]=COLOR_WHITE;
    }

    x = y = 100;
    xMax = 100;
    xMin = -xMax;
    yMax = 10;
    yMin = -yMax;
    p = toMath(x,y);

    x = *p;
    y = *(p + 1);

    array[] = COLOR_RED;

    printf("%d ",*p);
    printf("%d\n",*(p + 1));

    bmp_create("./white.bmp",array,w,h);

    free(array);

}

