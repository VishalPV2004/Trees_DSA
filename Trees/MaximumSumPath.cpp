#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

    int maxi = INT_MIN;
    int d(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        
        int lh = max(0,d(root->left));
        int rh = max(0,d(root->right));

        maxi = max(maxi, lh + rh + root->val);
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        d(root);
        return maxi;
    }

class Solution {
public:
    int maxi = 0;

    int d(TreeNode* root)
    {
        if (root == nullptr)
           return 0;
        
        int lh = d(root->left);
        int rh = d(root->right);

        maxi = max(maxi,lh+rh);
        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(Node* root) {
         d(root);
         return maxi;
    }
};

int main()
{
   struct TreeNode * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   
   Solution obj;
   int k = obj.diameterOfBinaryTree(root);
   cout<<k;
}