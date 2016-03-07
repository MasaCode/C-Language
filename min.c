#include <stdio.h>



int input(int number[]){
	char decision;
	int i=0;
	do{
		printf("Please enter the number:");
		scanf("%d",&number[i]);
		i++;
		printf("Do you wanna enter more number?(y/n):");
		scanf(" %c",&decision);
	}while(decision != 'n' && decision != 'N');	
	return i;
}


int  compare(int number[],int count){
	int i=0,j=0,min=100;
	for(i=0; i<count; i++){
		if(min > number[i]){
			min = number[i];
		}
	}
	return min;
}


void main(){
	int count=0,min=0,number[30];
	
	count = input(number);
	
	min = compare(number,count);
	
	printf("minimum number is %d\n",min);
}
