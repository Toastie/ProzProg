#include <stdio.h>
#include <stdint.h>

 long double e,n;

int main(){
    e = 0;
    for (int i = 0; i < 25; i++){
        n = 1;
        //Fakultät von i wird berechnet
        for (int j = i;j > 0; j--){
            n = n * j;
        }
        //Bildung der Summe
        e = e + (1/n);
        printf("    %0.20Lf\n",e);
    }
    return(0);
}
