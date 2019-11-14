#include <stdio.h>

float x,y;

int main(){
	x = -5;
	printf("x\t\t\t\ty\n");
	while(x <= 5){
		y = x * x;
		printf("%f\t",x);
		printf("%f\n",y);
		x = x + 0.125;
	}
	return(0);
}