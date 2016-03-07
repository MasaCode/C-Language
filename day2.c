#include <stdio.h>


int calculate(int a, int b){

	int ans=0, sum=0,R;
	sum = a/b;
	R = a%b;
	return R;
}

int main(){
	int num1=0,num2=0,r;
	printf("Please write 2 numbers\n");
	printf("number1 should be bigger than number2\n");
	printf("Answer's number:");
	scanf("%d",&num1);
	printf("matelial's number:");
	scanf("%d",&num2);

	while(num2>num1){
		printf("Rewrite:");
		scanf("%d", &num2);
	}
	r = calculate(num1,num2);
	printf("R is %d\n",r);
	return 0;
}
	
	
	
