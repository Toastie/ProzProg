#include <stdio.h>

int main(){
    printf("x\t");
    for(int i = 1; i <= 10; i++){
        printf("%d\t",i);
    }
    printf("\n");
    for(int t = 1; t <= 10; t++){
        printf("%d\t",t);
        for(int k = 1; k <= 10; k++){
            printf("%d\t", t * k);
        }
        printf("\n");
    }
    return(0);
}