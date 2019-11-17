#include <stdio.h>
#include <stdint.h>

uint64_t zahl[]= {1,12,123,1234,12345,123456,1234567,12345678,123456789};

uint64_t l;

int main(){
    for (int i = 0; i < 9; i++){
       printf("%Lu\n",zahl[i] * 8 + 9);
    }
    return(0);
}