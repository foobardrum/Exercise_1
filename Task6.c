//Tobias Egger, 16-728-016

#include <stdio.h>

double average(double A[], int n, int i){
	if (i == n-1) {
		return A[i]/n;
	} else {
	    return A[i]/n + average(A, n, i+1);
	}
}

int main(){
	int n,i;
	
	//init A
	double A[5] = {1,2,3,4,5};
	double result;
	
	//get length of A[]
	i = 0;
	while (A[i] != '\0'){
		i++;
	}
	// A[i] == '\0' -> n = i-1
	n = i-1;
	
	result = average(A, n, 0);
	
	printf("%f", result);
}

