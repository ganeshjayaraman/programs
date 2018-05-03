#include<stdio.h>

int a[1000][1000],temp;

int main() {
	int n,m,i,j,k;

	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	int max  = m > n ? m : n;
	printf("max : %d\n", max);
	for(i=0;i<max;i++) {
		for(j=i+1;j<max;j++) {
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

	int temp_m = n,temp_n = m;

	for(i=0;i<temp_m/2;i++) {
		for(j=0;j<temp_n;j++) {
			temp = a[j][i];
			a[j][i] = a[j][temp_n-i-1];
			a[j][temp_n-i-1] = temp;
		}
	}


/*
	for(i=0;i<temp_m/2;i++) {
		for(j=0;j<temp_n;j++) {
			temp = a[i][j];
			a[i][j] = a[temp_m-i-1][j];
			a[temp_m-i-1][j] = temp;
		}
	}
*/
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}