#include<stdio.h>

int a[1000][1000];

int main() {
	int i,j,n,m;
	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	i=0;j=0;
	while(i<m) {
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		i++;
		if(i>=m)
			break;
		for(j=n-1;j>=0;j--)
			printf("%d ",a[i][j]);
		i++;
	}
}