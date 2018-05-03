#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char a[1000],b[1000],temp;
	int i;
	scanf("%s",a);
	int n = strlen(a);
	for(i=0;i<n/2;i++) {
		temp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = temp;
	}

	printf("%s",a);

	int *arr = calloc(sizeof(int),n);

	printf("\n%d",arr[n-2]);
}