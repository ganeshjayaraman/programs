#include<stdio.h>

int a[10000][10000];

int main() {
	int m,n,i,j,row,col;

	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	row = 0; col = 0;

	while(row < m && col < n) {

		for(i=row;i<n;i++)
			printf("%d ",a[row][i]);
		row++;

		for(i=row;i<m;i++)
			printf("%d ",a[i][n-1]);
		n--;

		if( row < m) {
			for(i=n-1;i>=col;i--)
				printf("%d ",a[m-1][i]);
			m--;
		}

		if(col < n) {
			for(i=m-1;i>=row;i--)
				printf("%d ",a[i][col]);
			col++;
		}
	}
}