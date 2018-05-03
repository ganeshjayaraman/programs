#include <math.h>
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

void enqueue1(struct node *temp) {
    struct queue *t = malloc(sizeof(struct queue));
    t->n = temp;
    t->next = NULL;
    if(q1 == NULL) 
        q1 = t;
    else    
        store_t1->next = t;
    store_t1 = t;
}

void dequeue() {
    struct queue *temp = q;
    q = q->next;
    free(temp);
    temp = NULL;
}

void dequeue1() {
    struct queue *temp = q1;
    q1 = q1->next;
    free(temp);
    temp = NULL;
}

struct node *getFrontNode() {    
    return q->n;
}

struct node *getFrontNode1() {    
    return q1->n;
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


void insert1(int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    
    enqueue1(temp);
    
    if(root1 == NULL) 
        root1 = temp;
    else {        
            struct node *get_node = getFrontNode1();
            if(get_node->left == NULL) 
                get_node->left = temp;
            else if(get_node->right == NULL)
                get_node->right = temp;
            else {                    
                 dequeue1();
                get_node = getFrontNode1();
                if(get_node->left == NULL) 
                    get_node->left = temp;
                else if(get_node->right == NULL)
                    get_node->right = temp;
                else 
                    ;               
            }            
    }
}

bool AreMirror(struct node *a, struct node *b) {
    if(a == NULL && b == NULL)
        return true;
    else if(a == NULL || b == NULL)
        return false;
    return (a->data == b->data) & AreMirror(a->left, b->right) & AreMirror(a->right,b->left);
}

void inOrder(struct node *root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void makeMirror(struct node* root) {
    if(root == NULL)
        return;
    makeMirror(root->left);
    makeMirror(root->right);
    
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    int n,i=0,j;
    while(i++<8) {
        scanf("%d",&n);
        insert(n);        
    }
    i=0;
     while(i++<8) {
        scanf("%d",&n);
        insert1(n);        
    }
    
    inOrder(root);
    printf("\n\n");
    makeMirror(root);
    
    inOrder(root);
    
    AreMirror(root,root1) ? printf("YES\n") : printf("NO\n");
}

