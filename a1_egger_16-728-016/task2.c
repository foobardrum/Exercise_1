// Tobias Egger, 16-728-016
#include <stdio.h>
#include <math.h>

int main(){
	double value, avg, sum, closest, diff;
	double input[100];
	int i, j;
	
	i = 0;
	
	printf("Values of A separated by spaces (non-number to stop): ");
	while (scanf("%lf", &value) == 1) {
	  input[i] = value;
	  i++;
	}
	
	for(j=0; j <= i; j++){
		sum += input[j];
	}
	
	avg = sum/i;
	closest = input[0];
	
	for (j=1; j <= i; j++){
		diff =  fabs(closest-avg);
		if (fabs(input[j]-avg) < diff){
			closest = input[j];	
		}
	}
	printf("Average : %lf\nClosest element : %lf", avg, closest);
	
	return 0;
}
