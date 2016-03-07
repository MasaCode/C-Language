#include <stdio.h>





int calculator(int input){
	int temp =0,sum=0,result=0,count=10,flag=0,count2=1;
	do{
		flag = input%count;
		sum = ((input)%count-temp)/count2;
		result = result + sum;
		count = count*10;
		count2 = count2*10;
		temp = sum;
	}while(input>flag);
	return result;
}

void main(){
	int input,ans;
	printf("please input number:");
	scanf("%d",&input);
	
	ans = calculator(input);
	
	printf("answer is %d\n",ans);
}
