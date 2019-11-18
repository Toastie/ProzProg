#include <stdio.h>
#include <stdint.h>

uint64_t zahl[]={9,98,987,9876,98765,987654,9876543,98765432,987654321};
int zahl2[]={7,6,5,4,3,2,1,0,-1};

int main(){
    for(int i = 0; i < 9; i++){
        printf("%llu\n", zahl[i] * 9 + zahl2[i]);
    }
    return(0);
}