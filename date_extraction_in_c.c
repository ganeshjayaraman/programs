#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char s[] = __DATE__;
	printf("%s\n",s);
	int d,y;
	char *ptr = strtok(s," "),*m = malloc(sizeof(char)*100);
	
	m = ptr;	
	ptr = strtok(NULL," ");
	
	d = atoi(ptr);
	ptr = strtok(NULL," ");

	y = atoi(ptr);
	strtok(NULL," ");	
	printf("after\n");
	printf("%d %s %d",d,m,y);

	return 0;
}