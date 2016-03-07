#include <stdio.h>
#inlcude <string.h>

int calculate(char digit[]){
	int i,result=0,sum=0,len;
	len = strlen(digit);
	for(i=0; i<len; i++){
		sum = digit[i] - 48;
		result += sum;
	}
	
	return result;
}




void main(){
	int result;
	char digit[20];
	printf("please input number:");
	scanf("%s",digit);
		
	result = calculate(digit);
	
	printf("answer is %d\n",result);	
}
