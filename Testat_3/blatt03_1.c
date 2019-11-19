#include <stdio.h>

double e,c;
float f;
int n,g;

int main(){
    //Berechnung für einen Double
    g = 2;
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
        e = c;
    } while (g + e > g);
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
        f = c;
    } while (g + f > g);
    printf("Für einen Float:\t");
    printf("%e\n",f);
    return(0);
}