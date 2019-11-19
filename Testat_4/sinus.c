#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint64_t eexp(int x, int y){        //x hoch y
    uint64_t eexp = 1;
    for (int i = 1; i <= y; i++){
        eexp = eexp * x;
    }
    return(eexp);
}

uint64_t fak(int x){
    uint64_t fak = 1;
    for (int i = x; i > 1; i--){
        fak = fak * i;
    }
    return(fak);
}

long double esin(int x){
    long double summe, ergebnis;
    int k,i;
    k = 1;
    i = 0;
    ergebnis = 0;
    do{
        i = 2*k + 1;
        summe = (long double)eexp(x,i)/(long double)fak(i);
        if (k % 2 != 0){
            summe = summe * -1;
        }
        ergebnis = ergebnis + summe;
        k++;
    }while(ergebnis + summe > ergebnis);
    return(ergebnis);
}

int main(){
    printf("%Le\n", esin(5));
    double x = 5;
    double y = sin(x);
    printf("%e",y);
}