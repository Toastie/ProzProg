#include <stdio.h>

float x,y;

int main(){
	x = -5;
	printf("  x	  y\n");
	while(x <= 5){
		y = x * x;
		printf("%f	",x);
		printf("%f\n",y);
		x = x + 0.125;
	}
	return(0);
}