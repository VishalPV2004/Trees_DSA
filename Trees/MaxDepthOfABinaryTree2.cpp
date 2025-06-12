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

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1+max(left,right);
    }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
}