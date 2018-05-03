#include<stdio.h>

int main() {
	int a[10000],i,j,n;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int max_end_here = 0,max_so_far = 0;

	for(i=0;i<n;i++) {
		max_end_here += a[i];

		if(max_end_here < 0)
			max_end_here = 0;
		else {
			if(max_end_here > max_so_far) {
				max_so_far = max_end_here;
			}
		}
	}

	printf("Max sum : %d",max_so_far);
}