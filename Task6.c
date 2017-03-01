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
	double a[100];
	double result;
	
	printf("Type elements of A separated by spaces (type 'end' to stop): ");
		i = 0;
		while(scanf("%lf", &a[i]) == 1) {
		i++;
	}
	n = i;
	scanf("%*s");

	result = average(a, n, 0);
	printf("%lf", result);
	
	return 0;
}

