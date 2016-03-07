#include <stdio.h>

void main(){
	int line,i=0,j=0;
	
	printf("How many lines do you wanna see?:");
	scanf("%d",&line);
	
	for(i=0; i<line; i++){
		for(j=0; j<=i; j++){
			printf("*");
		}
		printf("\n");
	}
	
}
