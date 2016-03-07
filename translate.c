#include <stdio.h>

void main(){
	int number,sum,count,temp=1,ans[20],i=0;
	
	printf("please enter the number by dicimal:");
	scanf("%d",&number);

	printf("(%d) is (",number);
	
	temp = number;
	do{
		ans[i] = temp%2;
		temp = temp/2;
		i++;
		if(temp <2){
			ans[i] = temp;
		}
	}while(temp > 1);

	for(; i>=0; i--){
		printf("%d",ans[i]);
	}
	printf(")\n"); 
}
