#include <stdio.h>
#include <stdint.h>
//Send HELP! Ich checke nichts mehr :/
uint64_t pot(int x, int y){
    uint64_t pot;
    pot = (double) y;
    for (int i = 0; i <= x; i++){
        pot = pot * y;
    }
    return(pot);
}

double fak(int x){
    double fak;
    for (int i = x; i > 0; i--){
        fak = fak * i;
    }
    return(fak);
}

double esin(double x){
    long double ergebnis, summe;
    int i,k;
    i = 0;
    k = 0;
    ergebnis = summe = 0;
    while(ergebnis + summe >= ergebnis){
        k++;
        ergebnis = ergebnis + summe;
        i = 2*k+1;
        summe = ((long double)pot(i,x)/fak(i));
        if(k % 2 != 0){
            summe = summe * -1;
        }
    }
}

int main(){
    printf("%le\n",esin(5));
    return(0);
}
