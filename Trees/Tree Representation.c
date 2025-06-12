#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* create(int data)
{
    struct Node * root = (struct Node*)malloc(sizeof(struct Node));
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main()
{
    struct Node* root = create(1);
}