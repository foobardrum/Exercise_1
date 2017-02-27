// Tobias Egger, 16-728-016

#include <stdio.h>

void compareArrays(int arr1[], int arr2[], int len1, int len2, int output[]){
	int i, j, k,s;
	j, k,s = 0;
	
	for (i = 0; i < len1+len2; i++){
		if (j < len1 && k < len2){
			if(arr1[j] < arr2[k]){
				output[i] = arr1[j];
				j++;
			}else{
				output[i] = arr2[k];
				k++;
			}
		}else if(j >= len1 && k < len2){
			output[i] = arr2[k];
			k++;
		}else if(k >= len2 && j < len1){
			output[i] = arr1[j];
			j++;
		}
	}

}

int main(){
	int maxlength = 100;
	int alength, blength, r, s = 0;
	int a[maxlength], b[maxlength];
	int i;
	
  printf("Type elements of A separated by spaces (type 'end' to stop): ");
  while(scanf("%d", &a[r]) == 1) {
    r++;
  }
  scanf("%*s");
	
	printf("Type elements of A separated by spaces (type 'end' to stop): ");
	  while(scanf("%d", &a[s]) == 1) {
    s++;
  }
  scanf("%*s");

	while (a[alength] != '\0'){
		alength++;
	}
	
	while (b[blength] != '\0'){
		blength++;
	}	
	
	int output[alength + blength];
	compareArrays(a, b, alength, blength, output);
	
	printf("Result: ");
	for (i = 0; i < (alength+blength); i++){
		printf("%d", output[i]);
	}

	return 0;
}
