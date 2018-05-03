#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char a[26],b[26];

int main() {
	char str1[10000],str2[10000];
	int i,j;
	gets(str1);
	gets(str2);

	for(i=0;i<strlen(str1);i++) {
		a[str1[i]-97]+=1;
	}

	for(i=0;i<strlen(str2);i++) {
		b[str2[i]-97] += 1;
	}

	int maxi = strlen(str1),c=0;
	
	for(i=0;i<26;i++) {
		
			if(a[i] != b[i]) {
				c += abs( a[i] - b[i] );

			}
	}

	printf("c : %d\n",c);
}
