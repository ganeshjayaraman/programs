#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	struct node *left,*right;
}*root;

struct queue {
	struct node *temp;
	struct queue *next;
}*q,*store;

void enqueue(struct node *temp) {
	struct queue *t_q = malloc(sizeof(struct queue));
	t_q->temp = temp;
	t_q->next = NULL;

	if(q == NULL)
		q = t_q;
	else 
		store->next = t_q;
	store = t_q;
}

struct node *getFront() {
	return q->temp;
}

void dequeue() {
	struct queue *q1 = q;
	q = q->next;
	free(q1);
	q1 = NULL;
}

void insert(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	enqueue(temp);

	if(root == NULL)
		root = temp;
	else {
		struct node *t = getFront();
		if(t->left == NULL)
			t->left = temp;
		else if(t->right == NULL)
			t->right = temp;
		else {
			dequeue();
			t = getFront();
			if(t->left == NULL)
				t->left = temp;
			else if(t->right == NULL)
				t->right = temp;
			else 
				;
		}
	}
}

int get,f;

int level(struct node *root,int c1,int c) {	
	if(root == NULL)
		return 0;
	c++;
	if(root->data == c1) {		
		f=1;
		get = c;
		return get;
	}
	if(!f)
		level(root->left,c1,c);
	if(!f)
		level(root->right,c1,c);
	return get;
}

bool siblings(struct node *root,int c1,int c2) {
	if(root == NULL)
		return true;
	if(root->left != NULL && root->right != NULL)
		return ((root->left->data == c1 && root->right->data == c2) || siblings(root->left,c1,c2) & siblings(root->right,c1,c2));
	return false;
}

int clear() {
	f=0;
	return get;
}

bool cousins(int c1,int c2) {
	
	return (((level(root,c1,0) & clear()) == (level(root,c2,0) & clear())) & !siblings(root,c1,c2));
}

void find(struct node *root) {
	if(root == NULL)
		return ;
	find(root->left);
	printf("%d\n",root->data);
	find(root->right);
}

int main() {
	int n,i=0,data,c1,c2;
	scanf("%d",&n);
	while(i++<n) {
		scanf("%d",&data);
		insert(data);
	}

	//find(root);
	scanf("%d %d",&c1,&c2);
	cousins(c1,c2) ? printf("true") : printf("false");
}