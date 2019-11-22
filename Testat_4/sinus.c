#include <stdio.h>
#include <stdint.h>
#include <math.h>


int main(){
    double x,y,yold,k,summe;
    x = 15;
    k = 0;
    //Das erste Ergebnis der Summe ist immer X
    y = summe = x;
    printf("%0.1f\t",k);
    printf("%0.17lf\n",y);
    yold = y - 1;
    k++;
    while (y != yold){
        yold = y;
        //Berechnung des nächsten Kettenglieds mittels -altes Kettenglied * neuer Anteil 
        summe = (-summe)*((x*x)/((2*k+1)*(2*k)));
        //Berechnung der Summe
        y = y + summe;
        //Ausgabe des Zwischenergebnis
        printf("%0.1f\t",k);
        printf("%0.17lf\n",y);
        k++;
    }
    //Ausgabe des Endergebnis
    printf("Sinus von %0.1lf:\n",x);
    printf("Eigenes Ergebnis:\t%0.17lf\n",y);
    printf("Ergebnis von math.h:\t%0.17lf\n",sin(x));
    return(0);
}