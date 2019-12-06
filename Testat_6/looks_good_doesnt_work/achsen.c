#include <stdlib.h>
#include <stdint.h>
#include "./libBMP.h"



int main(){
    int w,h,ges;
    uint32_t *array;

    printf("Höhe:");
    scanf("%d",&h);
    printf("Breite:");
    scanf("%d",&w);
    
    ges = w * h;

    array = malloc(ges * sizeof(uint32_t));

    for (int i = 0; i < ges; i++){
        array[i] = COLOR_WHITE;
    }

}