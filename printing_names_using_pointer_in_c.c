#include<stdio.h>
#include<stdlib.h>

int main() {

	int n;
	scanf("%d",&n);
	char **names = malloc(sizeof(char *)*(n+1));
	int i;
	for(i=0;i<n+1;i++) {
		printf("%d\n", i);
		names[i] = malloc(sizeof(char)*100);
		gets(names[i]);
	}

	for(i=0;i<n+1;i++) {
		puts(names[i]);
	}
}