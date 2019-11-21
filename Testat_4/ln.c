#include <stdint.h>
#include <stdio.h>
#include <math.h>


long double eexp(long double x, long double y){  //x hoch y
    long double eexp = 1;
    for (int i = 1; i <= y; i++){
        eexp = eexp * x;
    }
    return(eexp);
}

int main(){
    double x,y,yold,summe,k;
    //Abfrage des gewünschten X Wertes
    printf("ln(x); 0 < x <= 2; x = ");
    scanf("%lf",&x);
    k = 1;
    //Das erste Ergebnis ist immer x - 1
    y = summe = x - 1;
    printf("%0.1lf\t",k);
    printf("%0.17lf\n",y);
    //Ändern von yold damit die Schleife durchläuft
    yold = y - 1;
    k++;
    while (y != yold){
        yold = y;
        //Berechnung des nächsten Kettenglieds
        summe = eexp(-1,k+1)*(eexp(x - 1,k)/k);
        //Bildung der Summe
        y = y + summe;
        //Ausgabe des Zwischenergebnis
        printf("%0.1lf\t",k);
        printf("%0.17lf\n",y);
        k++;
    }
    //Ausgabe des Endergebnis
    printf("Eigenes Ergebnis:\t%0.17lf\n",y);
    printf("Ergebnis von math.h:\t%0.17lf\n",log(x));
    return(0);
}