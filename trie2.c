#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node {
	struct node *children[26];	
	bool isWord;
};

struct node *getNode() {
	int i;
	struct node* t = (struct node *)malloc(sizeof(struct node*));
	for(i=0;i<26;i++) 
		t->children[i] = NULL;
	t->isWord = false;
	
	return t;
}

int getIndex(char a) {		
	return (int)(a - 97);
}

void insert(struct node* root,char str[]) {
	int i,index;
	struct node *temp = root;
	
	for(i=0;i<strlen(str);i++) {	
		index = getIndex(str[i]);
		printf(" %d %c",index,str[i]);	
		if(!temp->children[index]){					
			temp->children[index] = getNode();															
		}		
		temp = temp->children[index];		
					
	}
	
	temp->isWord = true;
}
/*
bool isLastNode(struct node *temp) {
	int i;
	for(i=0;i<26;i++) 
		if(temp->children[i])
			return 0;
	return 1;
}

void getSuggestion(struct node* temp, char str[]) {
	int i,index;
	
	for(i=0;i<26;i++) {
		index = getIndex(str[i]);
		if(temp->children[index]) {
			char p[2] = "\0";
			p[0] = (char)index;
			strcat(str,p);
			
			temp = temp->children[index];
			getSuggestion(temp,str);
		}
		
		if(temp->isWord)
			printf("%s\n",str);
	}
}

int autocomplete(struct node* root, char str[]) {
	int i,index;
	
	struct node *temp = root;
	for(i=0;i<strlen(str);i++) {	
		index = getIndex(str[i]);
		
		if(!temp->children[index])
			return 0;
			
		temp = temp->children[index];
	}
	
	bool isWord = (temp->isWord == true);
	
	bool isLast = isLastNode(temp);
	
	if(isWord && isLast)
		return 0;	
	
	if(!isLast) {
		printf("Suggestions are : \n");
		getSuggestion(temp,str);
		return 1;
	}
}
*/
int main() {
	int n,i=0;
	char str[100],str1[100];
	
	//scanf("%d",&n);
	struct node *root = malloc(sizeof(struct node *));
    root->isWord = false;
 
    for (int i = 0; i < 26; i++)
        root->children[i] = NULL;
	
	insert(root, "hello");
    insert(root, "dog");
    insert(root, "hell");
    insert(root, "cat");
    insert(root, "a");
    insert(root, "hel");
    insert(root, "help");
    insert(root, "helps");
    insert(root, "helping");


	scanf("%s",str1);
//	if(!autocomplete(root,str1))
		printf("No words can be suggested");
	return 0;
}