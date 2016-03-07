#include <stdio.h>


double calculate(int value){
	double final=0;
	final = value + value*0.12;
	return final;
}


void main(){
	double final,value;
	
	printf("Please enter the value(dollar):");
	scanf("%lf",&value);

	
	final = calculate(value);
	printf("The total is $%.2f\n",final);
}
