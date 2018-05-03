#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[1000];
	int k,i=0,n,j=0,c[1000];
	gets(str);

	n = strlen(str);
	while(i<n) {
		if(str[i] == 32)
			c[j++] = i;
		i+=1;
	}
	int end = n;
	while(j>0) {
		j-=1;
		int start = c[j];
		for(k=start+1;k<end;k++) {
			printf("%c",str[k]);
		}
		printf(" ");
		end = c[j];
	}
	k=0;
	while(k<end) {
		printf("%c", str[k]);
		k+=1;
	}
} 