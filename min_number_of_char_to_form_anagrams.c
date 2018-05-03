#include<stdio.h>

char a[26];

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
(
	int maxi = strlen(str1),c=0;
	if(strlen(str1) < strlen(str2)) 
		maxi = strlen(str1);
	
	for(i=0;i<maxi;i++) {
		if(str1[i] != '\0' && str2[i] != '\0') {
			if(a[str1[i]-97] != b[str2[i]-97]) {
				c += abs( a[str1[i]-97] - b[str2[i]-97] );
			}
		}

		else {
			if(i>=strlen(str1)) {
				if(!a[str2[i]-97])
					c += b[str2[i]-97];
			}
			else {
				if(!b[str1[i]-97])
					c += a[str1[i]-97];
			}
		}
	}
}