
/* link : http://www.geeksforgeeks.org/zoho-off-campus-drive-set-26-software-developer/ 4th qs */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int f;

bool check(int a[100][100], int i, int j, int n, bool *visited[n]) {
	int ret1=0,ret2=0;

	if(i<n && j<n && !visited[i][j] && a[i][j+1]) {		
		ret1 = check(a,i,j+1,n,visited);
	}
	if(i<n && j<n && !visited[i][j] && a[i+1][j]) {
		visited[i][j] = 1;
		ret2 = check(a,i+1,j,n,visited);
	}

	if(i==n-1 && j==n-1) {
		if(a[i][j] == 1){
			f=1;
			printf("%d %d\n", i,j);
			return true;
		}
		return false;
	}
	if(f) {
		if(a[i][j])
			printf("%d %d\n", i,j);
	}


	if(ret1 == 1 || ret2 == 1)
		return true;
	return false;
		
}

int main() {
	int i,j,n,k,a[100][100];
	scanf("%d",&n);
	bool *visited[100];

	for(i=0;i<n;i++) {
		visited[i] = calloc(n,sizeof(bool));
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);			
		}
	}

	check(a,0,0,n,visited);
}