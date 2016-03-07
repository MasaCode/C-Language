#include <stdio.h>



int input(int number[]){
	int i=0;
	char decision;
	
	do{
		printf("enter the number:");
		scanf("%d",&number[i]);
		i++;
		printf("Do you wanna enter more?(y/n) :");
		scanf(" %c",&decision);
	}while(decision != 'n' && decision != 'N');
	return i;
}


int  calculate(int number[],int count){
	int i=0,sum=0;
	
	for(i=0; i<count; i++){
		sum += number[i];
	}
	
	return sum;
}


void output(int number[],int sum,int count){
	int i=0;
	double per;
	printf("The total is %d\n",sum);
	for(i=0; i<count; i++){
		per = ((double)number[i]/(double)sum)*100;
		printf("%d's pacentage is %.2f%%\n",number[i],per);
	}
}

void main(){
	int number[20],sum=0,count=0;
	double aver;
	
	count = input(number);
	sum = calculate(number,count);
	output(number,sum,count);
}	
