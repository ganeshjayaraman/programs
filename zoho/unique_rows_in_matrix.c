#include<stdio.h>
#include<math.h>

int a[100][100],val[100],pos[100],pic;

int main() {
	int i,j,m,n,ic=0;
	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++) 
		for(j=0;j<n;j++) 
			scanf("%d",&a[i][j]);


	for(i=0;i<m;i++) {
		int num = 0;
		for(j=n-1;j>=0;j--) {
			num += ((int)pow(2,(n-1-j))) * a[i][j];
		}
		printf("val : %d\n", num);
		int f = 0;
		for(j=0;j<ic;j++) {
			if(val[j] == num) {
				f=1;
				break;
			}
		}

		if(!f) {
			val[ic++] = num;
			pos[pic++] = i;
		}
	}

	for(i=0;i<pic;i++) {
		printf("rows : %d \n", pos[i]);
	}
}