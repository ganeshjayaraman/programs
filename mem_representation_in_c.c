#include<stdio.h>
typedef char  *byte_pointer;


int main() {
	
	int i=30,k;

	float j=10.0000;

	byte_pointer *x = (byte_pointer) i;
	printf(" size : %d\n",sizeof(i));
	for(k=0;k<sizeof(i);k++) 
		printf("%.2x ",x[k]);
	printf("\n\n");
	printf(" size : %d\n",sizeof(j));
	x = (byte_pointer) j;
	for(k=0;k<sizeof(j);k++) 
		printf("%.2x ",x[k]);
}