#include <stdio.h>

int main(){
    for(int i = 100; i > 0; i--){
        if(i % 3 == 0){
            printf("%d\n",i);
        }
    }
    return(0);
}