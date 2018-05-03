#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int t,i,j,k;
	char arr[10000];
	scanf("%d",&t);
	
	while(t--) {
	    scanf("%s",arr);
	    int n = strlen(arr);
	    i=0;
	    while(i<n) {
	        //printf("%d",i);
	        if(i<n/2) {
	            for(j=0;j<i;j++)
	                printf(" ");
	            printf("%c",arr[i]);
	            for(j=i;j<n-i-1;j++)
	                printf(" ");
	            printf("%c\n",arr[n-i-1]);
	        }
	        else if(i==n/2) {
	            for(j=0;j<n/2;j++)
	                printf(" ");
	           printf("%c\n",arr[n/2]);
	        }
	        else {
	            for(j=0;j<n-i-1;j++)
	                printf(" ");
	            printf("%c",arr[n-i-1]);
	            for(j=n-i-1;j<i;j++)
	                printf(" ");
	            printf("%c\n",arr[i]);
	        }
	        i++;
	    }
	    
	}
	return 0;
}