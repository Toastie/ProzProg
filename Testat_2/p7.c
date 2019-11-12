#include <stdio.h>

int main(){
	for(int i = 6; i> 0; i--){
		for(int k = i; k > 0; k--){
			printf("*");
		}
		printf("\n");
	}
	return(0);
}
