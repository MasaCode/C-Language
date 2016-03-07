#include <stdio.h>
#include <stdlib.h>


int user(int *sum){
	int card=0;
	card = rand()%10 + 1;
	*sum = *sum + card;
	return card;
}

int cp(int *sum){
	int card = 0;
	card = rand()%10 + 1;
	*sum = *sum + card;
	return card;
}


int player(){
	int sum = 0,card=0,i=0;
	char decision;	

	for(i=0; i<2; i++){
		card = user(&sum);
		printf("you hit %d\n",card);
	}
	do{
		printf("--------------------------\n");
		printf("|your total is %d        |\n",sum);
		printf("--------------------------\n");
		if(sum > 21){
			break;
		}
		printf("Do you wanna hit?(y/n):");
		scanf(" %c",&decision);
		if(decision == 'Y' || decision == 'y'){
			card  = user(&sum);
			printf("you hit %d\n",card);
			printf("--------------------------\n");
                	printf("|your total is %d        |\n",sum);
                	printf("--------------------------\n");
		}else{
			break;
		}
	}while(0);
	
	return sum;
}


int computer(){
	int sum = 0,card=0,i=0;
	for(i=0;i<2; i++){
		card  = cp(&sum);
		printf("computer hits %d\n",card);
	}
	
	while(sum < 16){
			card = cp(&sum);
			printf("computer hits %d\n",card);
			if(sum > 21){
				break;
			}
	}
	printf("-------------------------\n");
        printf("|computer's total is %d |\n",sum);
        printf("-------------------------\n");
	
	return sum;
}



void battle(int computer, int player){
	if(computer > player){
		printf("you lose the game.....\n");
	}else if(computer < player){
		printf("you win the game!!!!!!\n");
	}else if(player == 0 && computer == 0){
		printf("you lose the game.....\n");
	}else{
		printf("Push!!!!!!\n");
	}
	
	printf("\n\n\n");
}


void main(){
	int csum,psum;
	char decision;

	do{
		psum = player();
		if(psum >21){
			printf("you are bust.....");
			psum = 0;
		}
		csum = computer();
		if(csum > 21){
			printf("computer is bust!!!!!");
			csum = 0;
		}
		battle(csum,psum);
		printf("Do you wanna play again?(y/n):");
		scanf(" %c",&decision);
	}while(decision != 'N' && decision != 'n');
}
