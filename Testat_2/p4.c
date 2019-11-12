#include <stdio.h>

int a;

int main(){
	a = 23;
	for(int i = a; i > 1; i--){
		if(a % i == 0){
			printf("%d ",i);
		}
	}
	return(0);
}