#include <stdio.h>

void main(){
	int number,sum,count,temp=1,ans,i=0;
	
	printf("please enter the number by dicimal:");
	scanf("%d",&number);

	printf("%d is ",number);
	
	temp = number;
	do{
		ans= temp%2;
		temp = temp/2;
		i++;
		printf("%d",ans);
		if(temp <2){
			printf("%d",temp);
		}
	}while(temp > 1);

	printf("\n");
}
