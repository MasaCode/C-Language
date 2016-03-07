#include <stdio.h>


void mname(int month){
	switch(month){
		case 1:
			printf("name of month is January\n");
			break;
		
		case 2:
			printf("name of month is February\n");
			break;
		
		case 3:
			printf("name of month is March\n");
			break;
		
		case 4:
			printf("name of month is April\n");
			break;
		
		case 5:
			printf("name of month is May\n");
			break;
		
		case 6:
			printf("name of month is June\n");
			break;
		
		case 7:
			printf("name of month is July\n");
			break;
			
		case 8:
			printf("name of month is August\n");
			break;
		
		case 9:
			printf("name of month is October\n");
			break;
		
		case 10:
			printf("name of month is September\n");
			break;
		
		case 11:
			printf("name of month is November\n");
			break;
		
		case 12:
			printf("name of month is December\n");
			break;
	}
}


void main(){
	int month;
	printf("Please enter the number of month:");
	scanf("%d",&month);
	
	mname(month);
}
