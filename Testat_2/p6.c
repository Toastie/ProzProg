#include <stdio.h>
#include <stdint.h>

int16_t i,j;
int32_t a;

int main(){
    a = 0;
	i = j = 67;
	while(i >= j){
		i++;
		a++;
	}
	printf("%d",a);
	return(0);
}
