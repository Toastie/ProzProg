#include <stdio.h>

int zahl,fak, i;

int main(){
    zahl = i = 3;
    fak = 1;
    do{
        fak = fak * zahl;
        zahl--;
    }while(zahl > 0);
    printf("%d! = %d", i, fak);
}