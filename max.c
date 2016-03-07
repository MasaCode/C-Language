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
	int i=0,j=0,max=0;
	for(i=0; i<count; i++){
		if(max < number[i]){
			max = number[i];
		}
	}
	return max;
}


void main(){
	int count=0,max=0,number[30];
	
	count = input(number);
	
	max = compare(number,count);
	
	printf("maximum number is %d\n",max);
}
