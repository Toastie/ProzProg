#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t a, b;

int main() {    
    a = 1058;
    b = 58;

    while (a != 0 && b != 0){
        if (a > b){
            a = abs(a - b);
        }
        else{
            b = abs(a - b);
        }
    }
    if (a == 0){
        printf("%u\n", b);
    }
    else{
        printf("%u\n", a);
    }
}