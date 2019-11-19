#include <stdio.h>
#include <stdint.h>

uint64_t eexp(int x, int y){        //x hoch y
    uint64_t eexp = 1;
    for (int i = 1; i <= y; i++){
        eexp = eexp * x;
    }
    return(eexp);
}

long double arctan(double x){
    long double ergebnis, summe,i;
    int k;
    ergebnis = 0;
    k = i = 0;
    do{
        k++;
        i = 2 * (long double)k + 1;
        summe = (long double)eexp(x,i)/i;
        if (k % 2 != 0){
            summe = summe * -1;
        }
        printf("%Le\n",summe);
        
    ergebnis = ergebnis + summe;
    }while(ergebnis + summe >= ergebnis);
    return(ergebnis);
}

int main(){
    printf("%Le\n",arctan(1));
    return(0);
}