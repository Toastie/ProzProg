#include <stdio.h>
#include <stdint.h>
#include <math.h>

long double eexp(long double x, long double y){        //x hoch y
    long double eexp = 1;
    for (int i = 1; i <= y; i++){
        eexp = eexp * x;
    }
    return(eexp);
}

long double fak(long double x){  //Fakultät von X
    long double fak = 1;
    for (int i = x; i > 1; i--){
        fak = fak * i;
    }
    return(fak);
}


int main(){
    double x,y,yold,k,summe,n;
    //Abfrage des X Wertes
    printf("Sin(x); x = ");
    scanf("%lf",&x);
    printf("\n");
    k = 0;
    //Das erste ergebnis der Summe ist immer X
    y = summe = x;
    printf("%0.1f\t",k);
    printf("%0.17lf\n",y);
    yold = y - 1;
    k++;
    while (y != yold){
        yold = y;
        //Berechnung des Nenners um nicht doppelt zu arbeiten
        n = 2 * k + 1;
        //Berechnung des nächsten Kettenglieds
        summe = eexp(-1,k)*(eexp(x,n)/fak(n));
        //Berechnung der Summe
        y = y + summe;
        //Ausgabe des Zwischenergebnis
        printf("%0.1f\t",k);
        printf("%0.17lf\n",y);
        k++;
    }
    //Ausgabe des Endergebnis
    printf("Eigenes Ergebnis:\t%0.17lf\n",y);
    printf("Ergebnis von math.h:\t%0.17lf\n",sin(x));
    return(0);
}