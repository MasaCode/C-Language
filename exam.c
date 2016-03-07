#include <stdio.h>





int process(int number,int digit,int array[]){
	int i=0,temp =0,sum=0,result=0,count=10,flag=0,count2=1;
	do{
		flag = number%count;
		array[i] = ((number)%count-temp)/count2;
		count = count*10;
		count2 = count2*10;
		i++;
	}while(number>flag);
	return i-1;
}


void move(int array[],int ans[],int count){
	int i=0,a=0;
	for(i=count; i>=0; i--){
		ans[a] = array[i];
		a++;
	}
}

void find(int ans[],int count,int digit){
	int i=0;
	for(i=0; i<=count; i++){
		if(digit == ans[i]){
			printf("%d's location is %d\n",digit,i+1);
		}
	}
} 

int input(int *number){
	int digit,num=0;
	printf("please enter number:");
	scanf("%d",&num);
	*number = num;
		
	printf("Please enter the digit(0-9):");
	scanf("%d",&digit);
	return digit;
	
}




void main(){
	int array[30],ans[30],digit,count,number;
	
	digit = input(&number);
	
	count = process(number,digit,array);
	
	move(array,ans,count);
	
	find(ans,count,digit);

}
