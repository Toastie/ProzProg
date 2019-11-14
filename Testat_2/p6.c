#include <stdio.h>
#include <stdint.h>

int16_t i,j,a;

int main(){
    a = 1;
	j = 67;
	i = j + 1;
	while(i >= j){
		i++;
		a++;
	}
	printf("Alle positiven Zahlen <= %d",a);
	return(0);
}
