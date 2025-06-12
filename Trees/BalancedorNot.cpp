#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

    int checkHeight(TreeNode* root)
    {
        if (root == NULL)
         return 0;
        int left = checkHeight(root->left);
        if (left == -1)
           return -1;
        
        int right = checkHeight(root->right);
        if (right == -1)
           return -1;
        
        if (abs(left-right) > 1)
           return -1;
        
        return max(left,right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL)
           return true;
        return checkHeight(root) != -1;
    }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
}