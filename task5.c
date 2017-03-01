//Tobias Egger, 16-728-016

#include <stdio.h>

int sum(int a[], int i, int n) {
	if (i == n-1) {
		return a[i];
	} else {
		return a[i] + sum(a, i+1, n);
	}
}

int main() {
	int i, n;
	int a[100];
	
	i = 0;
	
	printf("Type elements of A separated by spaces (type 'end' to stop): ");
	while(scanf("%d", &a[i]) == 1) {
		i++;
	}
	n = i;
	scanf("%*s");
	
	int result = sum(a, 0, n);
	printf("sum: %d", result);
	
	return 0;
}

