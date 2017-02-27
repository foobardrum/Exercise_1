// Tobias Egger, 16-728-016
#include <stdio.h>

void concatenateReversed(char input[], char output[]){
	int wordlength;
	int i;
	
	wordlength = 0;
	while (input[wordlength] != '\0'){
		wordlength++;
	}
	
	for (i = 0; i < wordlength; i++){
		output[i] = input[i];
		output[2*wordlength-i-1] = input[i];
	} 
	
	output[2*wordlength] = '\0';
}

int main(){
	int maxlength = 100;
	char input [maxlength];
	char output [2*maxlength];
	
	printf("Type a string: ");
	scanf("%s",input);
	
	concatenateReversed(input, output);
	
	printf("Result string: %s", output);
	
	return 0;
}
