#include <stdio.h>


void repeat(){
	int i=0;
	char decision,letter;
	do{
		printf("Please enter one letter:");
		scanf(" %c",&letter);
		if(letter=='a' || letter=='A' || letter=='i' || letter=='I' || letter == 'u' || letter=='U'|| letter=='e' || letter=='E' || letter=='o' || letter=='O'){
			printf("your letter is vowel!!\n");
		}else{
			printf("your letter is not vowel...\n");
		}
		
		printf("Do you wanna continue?(y/n)\n");
		printf("your decision:");
		scanf(" %c",&decision);
	}while(decision == 'y' || decision == 'Y');
}


void main(){
	repeat();
}


