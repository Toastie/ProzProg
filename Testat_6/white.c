#include <stdlib.h>
#include <stdint.h>
#include "./libBMP.h"

#define WIDTH 300
#define HEIGHT 300

int main(){
    uint32_t *array;

    array = malloc((WIDTH * HEIGHT) * sizeof(uint32_t));

    for (uint32_t i = 0; i < (WIDTH * HEIGHT); i++){
        array[i] = COLOR_WHITE;
    }
    
    bmp_create("./white.bmp",array,WIDTH,HEIGHT);

    free(array);
}
