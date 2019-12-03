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
    xMax = 100;
    xMin = -xMax;
    yMax = 10;
    yMin = -yMax;
    int x,y;
    int *p;
    x = y = 123;

    p = toMath(x,y);

    printf("%d ",*p);
    printf("%d\n",*(p + 1));

}

