#include<stdio.h>
#include<stdlib.h>

struct node {
	int val,count;
	struct node *next;
}*root,*store;

void push(int val, int count) {
	struct node *temp = malloc(sizeof(struct node));
	temp->val = val;
	temp->count = count;

	if(root == NULL)
		root = temp;
	else
		store->next = temp;
	store = temp;
}

void sort() {
	if(root == NULL)
		return;
	struct node *temp = root,*temp2;	
	int t_val,t_count;
	for(;temp->next!=NULL;temp = temp->next) {		
		for(temp2 = temp->next;temp2!=NULL;temp2 = temp2->next) {
			if(temp->count <= temp2->count) {
				t_val = temp->val;
				temp->val = temp2->val;
				temp2->val = t_val;

				t_count = temp->count;
				temp->count = temp2->count;
				temp2->count = t_count;
			}
		}
	}
}

void print() {
	struct node *temp = root;

	while(temp) {

		int count = temp->count;
		//printf("%d %d =>", temp->val,temp->count);
		while(count--) {
			printf("%d ", temp->val);
		}
		//printf("\n");
		temp = temp->next;
	}
}

int  main() {
	int i,n,j,a[10000],temp,store;
	scanf("%d",&n);
	for(i=0;i<n;i++) 
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			if(a[j] < a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	i=0;
	while(i<n) {
		store = i;		
		if(i<n && a[i] == a[i+1]) {
		while(i<n && a[i] == a[i+1]) {
			i++;
		}					
		//printf("%d %d\n", i,store);
		}
		push(a[i],i-store+1);
		i++;
	}
	
	sort();
	print();
}