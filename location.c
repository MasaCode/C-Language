#include <stdio.h>

#define M 30


int input(int location[],int number[]){
	int i=0,temp,j=0,masa,masa2,m=0,max=0;
	
	do{
		printf("Please enter the location:");
		scanf("%d",&location[i]);
		if(max < location[i]){
			max = location[i];
		}
		if(location[i] < 0){
			break;
		}
			
		printf("Please enter the number:");
		scanf("%d",&temp);
		
		for(j=0; j<i; j++){
			if(location[i] == location[j]){
				masa2 = number[i];
				for(m=location[i];m<M; m++){
					masa = number[m];
					number[m] = masa2;
					masa2 = masa;
				}
				max++;
				break;
			}
		}
	
		number[location[i]] = temp;
		i++;
	}while(location[i] >= 0);
	
	return max;
}



void output(int number[],int max){
	int i=0;
	for(i=0; i<=max; i++){
		printf("Location:%d\n",i);
		printf("number:%d\n",number[i]);
	}
}



void main(){
	int max,location[30],number[30]={0}; 
	
	max = input(location,number);
	
	output(number,max);
}
		
