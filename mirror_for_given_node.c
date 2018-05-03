#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	struct node *left,*right;
}*root,*parent,*ptr,*t;

struct stack {
	int data;
	struct stack *next;
}*top;

void insert(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if(root ==  NULL)
		root = temp;
	else {
		ptr = root;
		while(ptr) {
			parent = ptr;

			if(ptr->data < data) {
				ptr  = ptr->right;
			}
			else {
				ptr = ptr->left;
			}
		}

		if(parent->data < data) {
			parent->right = temp;
		}
		else {
			parent->left = temp;
		}
	}	
}

int f,s,gc;

bool push(int data) {
	struct stack *temp = malloc(sizeof(struct stack));
	temp->data = data;
	temp->next = NULL;
	gc++;
	if(top == NULL)
		top = temp;
	else {
		temp->next = top;
		top = temp;
	}
	if(data == 0)
		return false;
	return true;
}

void pop() {
	struct stack *t1 = top;
	top = top->next;
	printf("popped : %d\n", t1->data);
	free(t1);
	t1 = NULL;
	gc--;
}

int getTop() {
	return top->data;
}


void find(struct node *root, int data,bool status) {
	if(root == NULL)
		return ;	
	if(root->data == data) {		
		f = 1;		
		return ;
	}
	
	if(!f)
		find(root->left,data,push(0));	
	if(!f){
		pop();
	}
	if(!f) 
		find(root->right, data, push(1));
	if(!f)
		pop();
}

int f1;

int main() {
	int n,i,j,get,value;

	scanf("%d",&n);

	while(n--) {
		scanf("%d",&get);
		insert(get);
	}

	scanf("%d",&value);
	find(root,value,true);
	
	int a[gc];
	i=0;

	if(value == root->data)
		printf("Mirror : %d\n", value);
	else {
	while(top) {
		a[i++] = getTop();
		printf("%d ", getTop());
		pop();
	}
	t = root;
	int len = i;
	i=0;
	printf("\n");
	printf("len %d\n", len);
	while(i<len) {	
		printf("%d ",a[i]);	
		if(a[len-i-1] == 0) {
			if(t->right)
				t = t->right;
			else {
				printf("No Mirror found\n");
				f1=1;
				break;
			}
		} 
		else {
			if(t->left)
				t = t->left;
			else {
				printf("No Mirror found\n");
				f1=1;
				break;
			}
		}
		i++;
	}

	if(!f1)
		printf("Mirror :%d\n",t->data);
	}
}


