#include <stdio.h>

int reminder(int x,int y){
	int ans;
	ans = x%y;
	return ans;
}



void main(){
	int x,y,ans;
	printf("Please enter the 2 number\n");
	printf("number 1:");
	scanf("%d",&x);
	printf("number 2:");
	scanf("%d",&y);
	
	ans = reminder(x,y);
	
	printf("Reminder of number1/number2 is %d\n",ans);
}
