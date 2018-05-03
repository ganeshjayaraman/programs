#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char *str[1000],temp[1000];
	int i,j,n;

	scanf("%d",&n);

	for(i=0;i<n;i++){ 
		str[i] = malloc(sizeof(char)*10000);
		scanf("%s",str[i]);		
	}
	/*
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			if(strcmp(str[j], str[j+1]) > 0 ) {
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	*/

	/* Find the largest number of array problem */
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			char store[1000],store1[1000],store2[1000];
			strcpy(store1,str[j+1]);
			strcpy(store,str[j]);
			strcpy(store2,store);
			strcat(store,store1);
			strcat(store1,store2);
			if(strcmp(store, store1) < 0 ) {
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}

		}
	}

	for(i=0;i<n;i++)
		printf("%s",str[i]);
}