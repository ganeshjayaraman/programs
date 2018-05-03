#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char data;
	struct node *next;	
}*root,*store;

void push(char data) {
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;	

	if(root == NULL)
		root = temp;
	else 
		store->next = temp;
	store = temp;
}

void remove_non_alpha() {
	struct node *temp = root;
	struct node *t_store = temp;
	if(root == NULL)
		return;
	else {	
	while(temp) {				
		if(!((temp->data >= 65 && temp->data <= 90) || (temp->data >= 97 && temp->data <= 122) ))  {
			struct  node *temp2 = temp;		
			//printf("%c ", temp->data);
			t_store->next = temp->next;
			free(temp2);
			temp2 = NULL;			
		}
		else {
			t_store = temp;		
		}
	temp = temp->next;
	}
	}
}

void print() {
	struct node *temp = root;
	while(temp) {
		printf("%c", temp->data);
		temp = temp->next;
	}
}

int main() {
	char str[1000];
	int i=0,n;
	scanf("%s",str);

	while(i<strlen(str)) {
		push(str[i]);
		i++;
	}

	remove_non_alpha();
	print();
}