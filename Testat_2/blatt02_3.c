#include <stdio.h>
#include <stdint.h>

int main(){
    int N, leer, anzahl;

    //Variablen: N = größte Zahl; leer = Anzahl der benötigten Leerzeichen
    N = 9;

    // Schleife für den oberen Teil der Raute
    for (int i = 0; i <= N ; i++){
        leer = N - i;
        anzahl = 0;
        //Ausgabe der Leerzeichen
        for (int k = 0; k <=  leer; k++){
            printf(" ");
        }
        
        //Ausgabe der Zahlen der linken Seite
        for (int r = 1; r <= i; r++){
            printf("%d",r);
            anzahl++;
        }

        //Zahlen der rechten Seite
        for (int t = anzahl - 1; t > 0; t--){
            printf("%d",t);
        }

        //Beginn einer neuen Zeile
        printf("\n");
    }
    
    //Ausgabe des unteren Teil der Raute
    for (int l = N - 1; l > 0; l--){
        leer = N - l;

        //Leerzeilen
        for (int i = 0; i <= leer; i++){
            printf(" ");
        }

        //Linke Seite
        for (int i = 1; i < anzahl; i++){
            printf("%d", i);
        }

        //Rechte Seite
        for (int i = anzahl - 2; i > 0; i--){
            printf("%d", i);
        }
        
        //Anzahl der auszugebenden Zahlen wird um eins verringert
        anzahl--; 
        printf("\n");
    }
    return(0);
}