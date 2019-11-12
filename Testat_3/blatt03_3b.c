#include <stdio.h>

int a,b,c;

int main(){
    a = 1058;
    b = 58;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d\n",a);
    return(0);
}


/*  Modulo als while Schleife

    while(a - b >= 0){
        a = a - b;
    }

    Nach beenden der Schleife ist der Rest der Division in a gespeichert
*/