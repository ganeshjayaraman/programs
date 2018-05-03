#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

int main() {
	int n,i=0,j,k;
	scanf("%d",&n);
	bool *a = calloc(n,sizeof(bool));

	while(i<(((int)pow(2,n)))) {
		int temp = i;
		j=0;
		while(temp > 0) {
			a[j++] = temp%2;
			temp = temp/2;
		}

		for(k=n-1;k>=0;k--)
			printf("%d ", a[k]);
		i++;
		printf("\n");
	}
}