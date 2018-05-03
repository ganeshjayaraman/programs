#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char s1[1000],s2[1000];

	int a[26] = {0},i=0,b[26] = {0},f=0;

	scanf("%s",s1);
	scanf("%s",s2);
	int n = strlen(s1),n1 = strlen(s2);
	if(n != n1)
		printf("NOT");
	else {
	for(i=0;i<n;i++) {
		a[s1[i]-97] += 1;
	}
	for(i=0;i<n;i++) {
		b[s2[i]-97] += 1;
	}
	for(i=0;i<n;i++)
		if(a[i] != b[i]) {
			f = 1;
			break;
		}		
	}
	f ? printf("NOT") : printf("YES");
	return 1;
}