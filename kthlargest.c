#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *left,*right;
}*root,*ptr,*temp,*parent;

void insert(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	if(root == NULL)
		root = temp;
	else {
		ptr = root;

		while(ptr) {
			parent = ptr;
			if(ptr->data < data) {
				ptr = ptr->right;
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

int c,f;

int kthlargest(struct node *root, int k) {
	if(root == NULL)
		return 0;
	int s = kthlargest(root->right,k);

	if(++c == k) {
		f=1;
		return root->data;
	} 
	if(!f) {
		s = kthlargest(root->left,k);
	}

	return s;
}


int main() {
	int n,i,j,get,k;

	scanf("%d",&n);

	for(i=0;i<n;i++) {
		scanf("%d",&get);
		insert(get);
	}
	scanf("%d",&k);
	printf("largest : %d",kthlargest(root, k));
}