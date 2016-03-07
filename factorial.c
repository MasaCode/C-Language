#include <stdio.h>

int factorial(int number){
	int i=0,sum=1;
	printf("%d! is ",number);

	for(i=number; i>0; i--){
		sum = sum*i;
		if(i == 1){
			printf("%d",i);
		}else{
			printf("%d*",i);
		}
	}


	printf(" = %d\n",sum);
	return sum;
}



void main(){
	int number,ans;
	printf("please enter the number:");
	scanf("%d",&number);
	
	ans = factorial(number);
} 
