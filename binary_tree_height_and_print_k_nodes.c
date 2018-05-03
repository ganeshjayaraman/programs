include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left;
    struct node *right;    
}*root,*root1;

struct queue {
    struct node *n;
    struct queue *next;
}*q,*store_t,*store_t1,*q1;

void enqueue(struct node *temp) {
    struct queue *t = malloc(sizeof(struct queue));
    t->n = temp;
    t->next = NULL;
    if(q == NULL) 
        q = t;
    else    
        store_t->next = t;
    store_t = t;
}

void dequeue() {
    struct queue *temp = q;
    q = q->next;
    free(temp);
    temp = NULL;
}

struct node *getFrontNode() {    
    return q->n;
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
            struct node *get_node = getFrontNode();
            if(get_node->left == NULL) 
                get_node->left = temp;
            else if(get_node->right == NULL)
                get_node->right = temp;
            else {                    
                 dequeue();
                get_node = getFrontNode();
                if(get_node->left == NULL) 
                    get_node->left = temp;
                else if(get_node->right == NULL)
                    get_node->right = temp;
                else 
                    ;               
            }            
    }
}

int max(int a, int b) {
    return a>b ? a : b;
}

int printHeight(struct node *root) {
    if(root == NULL)
        return 0;
    return (max(printHeight(root->left),printHeight(root->right))+1);
}

int c = -1;

void printHeight2(struct node *root) {
    c++;
    if(root == NULL)
        return;
    if(c == 3)
        printf("%d ",root->data);
    printHeight2(root->left);
    c--;
    printHeight2(root->right);
    c--;
}

void inOrder(struct node *root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}


int main() {
    int n,i=0,j;
    while(i++<8) {
        scanf("%d",&n);
        insert(n);        
    }
    
    inOrder(root);
    printf("\n\n");
    printf("%d\n",printHeight(root));
    printHeight2(root);
}

