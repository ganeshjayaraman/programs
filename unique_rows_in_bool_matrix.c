#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int a[1000][1000];

struct node {
	bool isrowend;
	struct node *child[2];
}*root;


struct node *getNode() {
	struct node *temp = malloc(sizeof(struct node));
	temp->isrowend = false;

	temp->child[0] = NULL;
	temp->child[1] = NULL;

	return temp;
}

bool insert(int row,int m) {
	int i,val;
	struct node *temp = root;
	for(i=0;i<m;i++) {
		val = a[row][i];
		if(!temp->child[val]) {
			temp->child[val] = getNode();
		}		
		temp = temp->child[val];
		printf("\n");
	}

	if(temp->isrowend) 
		return false;
	temp->isrowend = true;
	return true;		

}

int main() {
	int n,m,i,j,c=0;
	int store[10000];

	scanf("%d %d",&n,&m);

	root = getNode();

	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) 
			scanf("%d",&a[i][j]);
		if(insert(i,m))
			store[c++] = i;
	}


	printf("\n");
	for(i=0;i<c;i++) {
		for(j=0;j<m;j++)
			printf("%d ", a[store[i]][j]);
		printf("\n");
	}
}