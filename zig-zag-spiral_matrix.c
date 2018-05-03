#include<stdio.h>

int a[10000][10000];

int main() {
	int m,n,i,j,row,col;

	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	j=0;

	for(i=0;i<m;i++) {
        col = j;
        row = i;        
		while(col < n && row >= 0) {
			printf("%d ",a[row][col]);
			col++;
			row--;
		}

	}
	//printf("cool :%d \n",a[0][0]);
	j=m-1;
	for(i=1;i<n;i++) {
		col = i;
        row = j;        
		while(col < n && row >= 0) {
			printf("%d ",a[row][col]);
			col++;
			row--;
		}
	}
}