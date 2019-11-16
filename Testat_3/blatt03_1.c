#include <stdio.h>

double e,c;
float f;
int n;

int main(){
    //Berechnung für einen Double
    n = 0;
    do{
        c = 1;
        n++;
        //Bilden der Zweierpotenz
        for (int i = 0; i < n; i++){
            c = c * 2;
        }
        // 1/2er potenz, damit wir eine negative zweierpotenz haben
        c = 1 / c;
        e = c / 2;
    } while (1 + e > 1);
    printf("Für einen Double:\t");
    printf("%e\n",e);
    //Berechnung für einen Float
    n = 0;
    do{
        c = 1;
        n++;
        //Berechnung der Zweierpotenz
        for (int i = 0; i < n; i++){
            c = c * 2;
        }
        c = 1 / c;
        f = c / 2;
    } while (1 + f > 1);
    printf("Für einen Float:\t");
    printf("%e\n",f);
    return(0);
}