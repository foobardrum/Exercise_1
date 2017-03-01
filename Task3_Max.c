

//Maximilian Boeker, 16-706-137//
#include <stdio.h>
#include <math.h>

void compare(int input_a[], int input_b[], int length_a, int length_b, int result[]){ //[] for array of integers
	int i, idx_a, idx_b;
	idx_a = idx_b = 0;
	
	for(i=0; i < (length_a + length_b); i++){
		// while loop funktioniert hier nicht, du brauchst ein if, damit du die nachfolgenden Konditionen mit else if's verbinden kannst ( denke ich)
		if(idx_a < length_a && idx_b < length_b){
			if(input_a[idx_a] > input_b[idx_b]){
				result[i] = input_b[idx_b];
				idx_b++;
			}
			else{
				result[i] = input_a[idx_a];
				idx_a++;				
			}
		}
		else if(idx_a >= length_a && idx_b < length_b){ // > hier unnötig?
			result[i] = input_b[idx_b];
			idx_b++;
		}
		else if(idx_b >= length_b && idx_a < length_a){ // > hier unnötig? und könnte es auch nur else sein?
			result[i] = input_a[idx_a];
			idx_a++;
		}
	}	
}

int main(){
	int maxlength = 100;
	int i, length_a, length_b, input_a[maxlength], input_b[maxlength];
	length_a = length_b = 0;
	
	printf("Type in elements for array A: ");
	while(scanf("%d", &input_a[length_a]) == 1){
		length_a++;
	}
	scanf("%*s");
	
	printf("Type in elements for array B: ");
	while(scanf("%d", &input_b[length_b]) == 1 ){
		length_b++;
	}
	scanf("%*s");
	
	int result[length_a + length_b - 1];
	
	compare(input_a, input_b, length_a, length_b, result);
	
	printf("Result: ");
	for(i=0; i < (length_a + length_b); i++){
		printf("%d", result[i]);
	} 
	
	return 0;
}
