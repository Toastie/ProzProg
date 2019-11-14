#include <stdio.h>

int main(){
    printf("K\t\t°C\n");
    for (int i = 0; i < 550; i =  i + 5){
        printf("%d\t\t",i);
        printf("%d\n",i - 273);
    }
    return(0);
}