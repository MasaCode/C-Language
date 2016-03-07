#include <stdio.h>

void check(int number){
	int reminder=0,i=0,flag=0;
	if(number != 1){
		for(i=2; i<number; i++){
			reminder = number%i;
			if(reminder == 0){
				printf("%d is not prime number\n",number);
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("%d is prime number\n",number);
		}
	}else{
		printf("%d is not prime number\n",number);
	}
}
	




void input(){
	int number;
	
	printf("Please enter the number:");
	scanf("%d",&number);
	
	check(number);
	
}


void main(){
	char decision;
	
	do{
		input();
		printf("Do you wanna continue?(y/n):");
		scanf(" %c",&decision);
	}while(decision != 'n' && decision != 'N');
}
