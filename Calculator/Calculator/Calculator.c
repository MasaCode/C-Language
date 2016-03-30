#include <stdio.h>

int Input(double Numbers[],char symbols[]){
	int i = 0;
	double temp = 0;
	char c;

	printf("Please enter the your fomula.(ex: 1 + 3 / 2)\n");
	printf("-> ");

	do{
		scanf("%lf%c", &temp, &c);
		while (c == ' '){
			scanf("%c", &c);
		}
		Numbers[i] = temp;
		symbols[i] = c;
		i++;
	} while (c != '\n');

	return i;
}

void Print(double Numbers[], char symbols[], int Count){
	int i = 0;
	for (; i < Count; i++){
		if (i == Count - 1){
			printf("%.1f", Numbers[i]);
		}
		else{
			printf("%.1f %c ", Numbers[i], symbols[i]);
		}
	}
}

double Calculate(double Numbers[], char symbols[], int *Count){
	int i = 0, j = 0;
	double answer;

	for (; i < *Count; i++){
		if (symbols[i] == '*' || symbols[i] == '/'){
			if (symbols[i] == '*'){
				Numbers[i] = Numbers[i] * Numbers[i + 1];
			}
			else if (symbols[i] == '/'){
				Numbers[i] = Numbers[i] / Numbers[i + 1];
			}

			for (j = i + 1; j < *Count - 1; j++){
				Numbers[j] = Numbers[j + 1];
				symbols[j - 1] = symbols[j];
			}
			i--;
			*Count = *Count - 1;
		}
	}

	answer = Numbers[0];
	for (i = 0; i < *Count - 1; i++){
		if (symbols[i] == '+'){
			answer += Numbers[i + 1];
		}
		else if (symbols[i] == '-'){
			answer -= Numbers[i + 1];
		}
	}

	return answer;
}



void main(){
	int count = 0;
	double Numbers[30],Answer;
	char symbols[30];
	count = Input(Numbers,symbols);
	Print(Numbers, symbols, count);
	Answer = Calculate(Numbers, symbols, &count);

	printf(" = %.1f\n", Answer);
}
