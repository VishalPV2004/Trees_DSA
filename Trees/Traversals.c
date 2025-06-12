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
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void preorder(struct Node *root)
{
    if (root == NULL)
       return;
    
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
       return;
    
    preorder(root->left);
    preorder(root->right);
    printf("%d",root->data);

}

void inorder(struct Node *root)
{
    if (root == NULL)
       return;
    
    preorder(root->left);
    printf("%d",root->data);
    preorder(root->right);
}


int main()
{
    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
}