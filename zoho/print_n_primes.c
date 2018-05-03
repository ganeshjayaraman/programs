#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	int i,n,j,N;
	scanf("%d",&n);
	N=(n-2)/2;
	bool *mark = calloc(N,sizeof(bool));
	
	 for (int i=1; i<=N; i++)
        for (int j=i; (i + j + 2*i*j) <= N; j++) {
            mark[i + j + 2*i*j] = 1;
            //printf("%d ", i+j+2*i*j);
        }
	printf("\n2 ");
	for(i=1;i<=N;i++)
		if(mark[i] == 0)
			printf("%d ",2*i+1);
}