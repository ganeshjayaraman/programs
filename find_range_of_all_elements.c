#include<stdio.h>

int main() {
	int a[10000],x,y,n,i,j;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	scanf("%d %d",&x,&y);

	for(i=0;i<n;i++)  {
		if(a[i] >= x && a[i] <= y)
			a[i] = 1;
		else 
			a[i] = 0;
	}
	int c=0,set=y-x+1;

	for(i=0;i<n;i++) {
		if(a[i])
			c++;			
	}
	printf("%d %d\n",set,c);
	set == c ? printf("YES") : printf("NO");
}