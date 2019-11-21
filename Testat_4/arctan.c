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


int main(){
    	double x,y, yold,n,summe,k;
        //Abfrage des X Wertes
        printf("-1 <= x <= 1;  x = ");
        scanf("%lf",&x);
        printf("\n");
        k = 0;
        
        //Exponent = 1, daher sind y == summe == x für den ersten Schritt
        y = summe = x;
        //Damit die Scleife durchläuft
        yold = y - 1;
        k = k + 1;
        while (y != yold){
            yold = y;
            //Berechnung des Nenners um nicht doppelt rechnen zu müssen
            n = 2*k+1;
            //Berechnung es nächsten Kettenglieds
            summe = eexp(-1,k)*(eexp(x,n)/n);
            //Berechnung der Summe
            y = y + summe;
            //Ausgabe des Zwischenergebnis
            printf("%0.1lf\t",k);
            printf("%0.17lf\n",y);
            k = k + 1;
        }
    //Ausgabe des Endergebnis
    printf("Eigenes Ergebnis:\t%0.17lf\n",y);
    printf("Ergebnis von math.h:\t%0.17lf\n",atan(x));
    return(0);
}