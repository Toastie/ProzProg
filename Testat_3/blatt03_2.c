#include <stdio.h>
#include <stdint.h>

double e,n;

int main(){
    e = 0;
    for (int i = 0; i < 15; i++){
        n = 1;
        for (int j = i;j > 0; j--){
            n = n * j;
        }
        e = e + (1/n);
        printf("    %0.10lf\n",e);
    }
    return(0);
}
