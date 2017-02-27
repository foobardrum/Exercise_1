#include <stdio.h>

int sumrec(int arr[], int i, int n) {
  if (i == n-1) {
    return arr[i];
  } else {
    return arr[i] + sumrec(arr, i+1, n);
  }
}

void main() {
  int maxarraylen = 100;
  int i;
  int n;
  int a[maxarraylen];

  printf("Type elements of A separated by spaces (type 'end' to stop): ");
  i = 0;
  while(scanf("%d", &a[i]) == 1) {
    i++;
  }
  n = i;
  scanf("%*s");

  int sum = sumrec(a, 0, n);
  printf("Sum: %d\n", sum);
}

// Linux, Mac: gcc task5.c -o task5; ./task5
// Windows: gcc task5.c -o task5; task5
