#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
}*root;

struct queue {
	struct node *temp;
	struct queue *next;	
}*q,*store;

bool isempty() {
	return root == NULL ? true : false;
}

void enqueue(struct node *temp) {
	struct queue *t = malloc(sizeof(struct queue)); 
	t->temp = temp;
	t->next = NULL;
	printf("queue : %d\n",t->temp->data);
	if(q == NULL)
		q = t;
	else 
		store->next = t;
	store = t;
}

struct node *getFront() {
	return q->temp;
}


void dequeue() {	
	struct queue *temp = q;
	q = q->next;
	free(temp);
	temp = NULL;
}

void insert(int data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	enqueue(temp);

	if(isempty())
		root = temp;
	else {
		struct node *front = getFront();
		if(front->left == NULL)
			front->left = temp;
		else if(front->right == NULL)
			front->right = temp;
		else {
			dequeue();
			front = getFront();
			if(front->left == NULL)
				front->left = temp;
			else if(front->right == NULL)
				front->right = temp;
			else 
				;
		}
	}
}

void print(struct node *root) {
	if(root == NULL)
		return;
	print(root->left);
	printf("%d ",root->data);
	print(root->right);
}

struct node *find(struct node *temp, int u) {
	if(temp == NULL)
		return NULL;
	if(temp->data == u)
		return temp;
	return find(temp->left,u);
	return find(temp->right,u);
}

int c,maxi,h,maxi_height;
void max_width(struct node *root, int c) {
	if(root == NULL)
		return ;
	if(root->left != NULL || root->right != NULL){
		c=c+1;
		if(c > maxi)
			maxi = c;
 	}
	
	max_width(root->left, c);
	max_width(root->right, c);
	
}


void max_height(struct node *root, int h) {
	h++;
	if(h > maxi_height)
		maxi_height = h;
	if(root == NULL)
		return ;	
	
	max_height(root->left, h);
	h--;
	max_height(root->right, h);
	h--;
}

int main() {
	int n,i=0,val,u,v;
	scanf("%d",&n);
	do {
		scanf("%d",&val);
		insert(val);
		i++;
	}while(i<n);

	print(root);
	scanf("%d %d",&u,&v);

	struct node *key = find(root,u);
	if(key == NULL) 
		printf("U is not present\n");
	else 
		key = find(key,v);
	if(key == NULL)
		printf("V is not present\n");
	else 
		printf("U is ancestor of V\n");

	max_width(root,c);
	printf("max_width: %d\n",maxi);

	max_height(root,h);
	printf("max_height : %d\n",maxi_height);
} 	