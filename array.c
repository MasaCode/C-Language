#include <stdio.h>


void input(int array[],int times){
	int i=0;
	for(i=0; i<times; i++){
		printf("Please enter %d's number:",i+1);
		scanf("%d",&array[i]);
	}
}



int  calculate(int array[],int times){
	int i=0,sum=0;
	
	for(i=0; i<times; i++){
		sum += array[i];
	}
	return sum;
}


void main(){
	int sum,array[20],times;
	
	printf("How many times do you continues?:");
	scanf("%d",&times);
	
	input(array,times);
	sum = calculate(array,times);
	
	printf("Total is %d\n",sum);
}
	
