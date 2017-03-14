//Tobias Egger, 16-728-016

#include <stdio.h>

int compare(char a, char b){
	int ascii_a = a;
	int ascii_b = b;
	int uc_a, uc_b;
	
	uc_a = a;
	uc_b = b;
	
	if (ascii_a > 90){
		uc_a = (ascii_a - 32);
	}
	if (ascii_b > 90){
		uc_b = (ascii_b - 32);
	}
	//printf("asc_a: %d\nasc_b: %d\nuc_a: %d\nuc_b: %d\n",  ascii_a, ascii_b, uc_a, uc_b);
	if (uc_a < uc_b){
		return -1;
	} else if (uc_b < uc_a){
		return 1;
	} else if (uc_a == uc_b){
		if (ascii_a > 90 && ascii_b < 90){
			return 1;
		}else if(ascii_b > 90 && ascii_a < 90){
			return -1;
		}else{
			return 0;
		}
	}
}
void selectionsort(char a[], int n){
	int i, j, s;
	char temp;
	for (i = 0; i < n; i++){
		s = i;
		for (j = i+1; j < n; j++){
			if (compare(a[j],a[s]) == -1){
				s = j;
			}
		}
		temp = a[i];
		a[i] = a[s];
		a[s] = temp;
	}	
}

int main(){
	int n;
	int i;
	char a[100];
	
	printf("Type a string: ");
	scanf("%s", a);
	n = 0;
	while (a[n] != '\0'){
		n++;
	}
	selectionsort(a,n);

	printf("Sorted string: %s", a);

	return 0;
}
