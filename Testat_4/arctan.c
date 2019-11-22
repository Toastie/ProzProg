#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(){
    	double x,y, yold,summe,k;
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
            //Berechnung es nächsten Kettenglieds; Neues Glied = -Altes Glied * neuen Anteil
            //Der Nenner muss durch den alten Nenner geteilt werden damit dieser sich kürzt
            summe = (-summe)*((x*x)/((2*k+1)/(2*k-1)));
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