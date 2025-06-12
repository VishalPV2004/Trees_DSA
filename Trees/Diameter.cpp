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

class Solution {
public:
    int maxi = 0;

    int d(Node* root)
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
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   
   Solution obj;
   int k = obj.diameterOfBinaryTree(root);
   cout<<k;
}