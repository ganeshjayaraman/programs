#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
}*root,*store;

void insert(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(root == NULL)
		root = temp;
	else {
		store->next = temp;
	}
	store = temp;
}

int get(int val) {
	int i=1;
	struct node *temp = root;
	while(i<val && temp) {
		i+=1;					
		temp = temp->next;
	}	
	if(temp == NULL) {
	//	printf("i = %d\n", i);
		return 0;
	}
	return temp->data;
}

void rev_print(int n) {
	while(n) {
		printf("%d->", get(n));
		n-=1;
	}
}

void print() {
	struct node *temp = root;
	while(temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int count() {
	int c=0;
	struct node *temp = root;
	while(temp) {
		c+=1;
		temp = temp->next;
	}
	return c;
}

int main() {
	int i=1,n,data;
	do {
		scanf("%d",&data);
		insert(data);
		printf("Continue ? ");
		scanf("%d",&n);
	} while(n);
	n=count();
	rev_print(n);

}