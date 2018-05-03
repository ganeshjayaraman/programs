#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	int i,temp,digit,num;
	char str[100000],str2[100000];

	scanf("%d %d",&digit,&num);

	sprintf(str,"%d",num);

	int len = strlen(str);
	int res;	
	for(i=0;i<len;i++) {
		char store[10000];		
		sprintf(store,"%d",digit + (int)str[i]-48);
		strcat(str2,store);
	}

	puts(str2);
}