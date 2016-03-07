#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100
#define N 500

int Data(char name[],char class[]){
	
	int i=0,len;
	printf("Please input your html's name:");
	scanf("%s",name);
	printf("Please input your class's name:");
	scanf("%s",class);
	len = strlen(class);
	return len;
 }
	

int open(char name[],char content[][M]){
	FILE *fp;
	int i=0;
	fp = fopen(name , "r");
	
	if(fp == NULL){
		printf("cannot open the file\n");
		exit(1);
	}else{
		while(fgets(content[i],100,fp) != NULL){
			printf("%s",content[i]);
			i++;
		}
	}


	fclose(fp);
	return i-1;
}


int find(char class[], char content[][M],int count,int len,int *num1){
	int i=0,j=0,a=0,flag=0;
	for(i=0; i<=count; i++){
		for(j=0; j<=M; j++){
			if(class[a] == content[i][j]){
				a++;
				j++;
				while(a <= len){
					if( class[a] == content[i][j]){
						if(a==(len-1)){
							*num1 = i;
							flag = 1;
						}
						a++;
					}else{
						break;
					}
					j++;
				}
			}
			a = 0;
		}
	}
	return flag;
}

void process(char content[][M], int num1,char tag[]){
	int i=0,j=0;
	while(i<=M){
		if(content[num1][i] == '<'){
			i++;
			while(content[num1][i] == ' '){
				i++;
			}
			while(content[num1][i] != ' ' &&  content[num1][i] != '>'){
				tag[j] = content[num1][i];
				i++;
				j++;
			}
			tag[j] = '\0';
			break;
		}
		i++;
	}
}				
				 

void output(char tag[],char content[][M],int num1,int count){
	int i=0,len=0,j=0,a=0,b=0,flag=0;
	char box[N][M],close[20];
	for(i=num1; i<=count; i++){
		for(j=0; j<M; j++){
			if(content[i][j] =='<'){
				j++;
				while(content[i][j] == ' '){
					i++;
				}
				while(content[i][j] != ' ' && content[i][j] != '>'){
					box[a][b] = content[i][j];
					j++;
					b++;
				}
				box[a][b] = '\0';
				a++;
				b=0;
			}
		}
	}


	for(i=0; i<=a; i++){
		if(strcmp(box[i],tag)==0){
			flag++;
		}
	}

	i=0; a=0;
	close[i] = '<';
	close[i+1] = '/';
	i= i+2;
	while(tag[a] != '\0'){
		close[i] = tag[a];
		a++;
		i++;
	}
	close[i] = '>';
	i = i+1;
	close[i] = '\0';
	
	printf("\n\n**********************OUTPUT*************************\n");
	for(i=num1; i<=count; i++){
		for(j=0; j<M; j++){
			a=0;
			if(content[i][j] == '<'){
				j++;
				if(content[i][j] == '/'){
					j++;
					while(content[i][j] == ' '){
						j++;
					}
					while(content[i][j] != '>' && content[i][j] != ' '){
						len = strlen(tag);
						if(content[i][j] == tag[a]){
							if( a == (len-1)){
								flag--;
							}
						}
						a++;
						j++;
					}
				}
			}
		}
		printf("%s",content[i]);
		if(flag == 0){
			break;
		}
	}
	printf("******************************************************\n");
		
}	

					

void main(){
	int count=0,i=0,len=0,num1,num2,place;
	char name[N],class[M],content[N][M],tag[20],statment[N][M];

	len = Data(name,class);
	
	printf("**************************************\n");
	printf("html:%s\n",name);
	printf("class:%s\n",class);
	printf("**************************************\n\n");

	count = open(name,content);
	place = find(class,content,count,len,&num1);

	process(content,num1,tag);

	output(tag,content,num1,count);
}

