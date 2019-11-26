#include <stdint.h>
#include <stdio.h>
#include <math.h>

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
        //-Vorgänger * Neuer anteil (Nenner wird durch den Alten geteilt damit dieser sich kürzt)
        summe = (-summe)*((x-1)/(k/(k-1)));
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