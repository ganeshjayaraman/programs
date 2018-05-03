#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	char str1[1000],str2[1000];
	scanf("%s %s",str1,str2);

	int i=0,j,len1,len2,f=0,start;
	len1 = strlen(str1);
	len2 = strlen(str2);

	while(i<len1) {
		j=0;
		if(i<len1 && j<len2 && str1[i] == str2[j])
			start = i;
		while(i<len1 && j<len2 && str1[i] == str2[j]) {
			i++;
			j++;
		}
		if(j==len2) {
			f=1;
			break;
		}
		i++;
	}
	if(f)
		printf("True & %d",start);
	else 
		printf("False");

}