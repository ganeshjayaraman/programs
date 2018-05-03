#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char str[10000],substr[1000];
	int f,i=0,j,c,store;
	scanf("%s %s",str,substr);
	int str_len = strlen(str),substr_len = strlen(substr);
	while(i<str_len) {		
		j=0;
		c=0;
		store = i;

		while(i<str_len && j<substr_len && ( str[i] == substr[j]) || substr[j] == '*') {
			//printf("%d %d\n", str[i],substr[j]);
			if(substr[j] == '*') {
			while(i<str_len && j<substr_len-1 && str[i] != substr[j+1]) {				
				printf("%c ", str[i]);
				i+=1;								
			}			
			j+=1;
			c+=1;
			continue;
			}
			
			c++;	
			j++;
			i++;
		}
		if(c == substr_len) {
			f=1;
			break;
		}
		i = store+1;
	}
	if(f)
		printf("True\n");
	else
		printf("False\n");
}