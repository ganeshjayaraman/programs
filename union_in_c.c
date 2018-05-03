#include<stdio.h>

int f,mid,a[1000],b[1000],temp,l;

int main() {
	int m,n,i,j,k;

	scanf("%d %d",&m,&n);

	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(j=0;j<n;j++)
		scanf("%d",&b[j]);
	

	if(m < n) {
	for(i=0;i<m;i++) {
		for(j=0;j<m-i-1;j++) {
			if(a[j] > a[j+1]) {
			temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
		}
	}

	}

	else {
		for(i=0;i<n;i++) {
			for(j=0;j<n-i-1;j++) {
				if(b[j] > b[j+1]) {
					temp = b[j];
					b[j] = b[j+1];
					b[j+1] = temp;
				}
			}
		}	
	}

	if(m<n) {
		l=m;
		for(k=0;k<n;k++) {		
			i=0;
			j=m-1;
			f=0;
			while(i<=j) {
				mid = (i+j)/2;
				if(a[mid] == b[k]) {					
					f=1;break;
				}
				else if(a[mid] < b[k]) 
					i=mid+1;
				else 
					j=mid-1; 
			}
			if(f == 1) {
				printf("%d ", b[k]);
			}
		}
	for(i=0;i<l;i++);
		//printf("%d ", a[i]);
	}
	else {
		l=n;
		for(k=0;k<m;k++) {		
			i=0;			
			j=n-1;
			f=0;
			while(i<j) {
				mid = (i+j)/2;
				if(b[mid] == a[k]) {
					f=1;break;
				}
				else if(b[mid] < a[k]) 
					i=mid+1;
				else 
					j=mid-1; 
			}
			if(f == 0) {
				b[l++] = a[k];
			}
		}	
	for(i=0;i<l;i++)
		printf("%d ", b[i]);
	}


}