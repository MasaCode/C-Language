#include <stdio.h>

int calculate(int x,int y){
	int i=0,ans=1;
	
	for(i=0; i<y; i++){
		ans *= x;
	}
	return ans;
}


void main(){
	int ans=0,x,y;
	
	printf("Please tenter the 2 numbers\n");
	printf("number 1:");
	scanf("%d",&x);
	printf("number 2:");
	scanf("%d",&y);
	
	ans = calculate(x,y);
	
	printf("%d^%d is %d\n",x,y,ans);
}
