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
        queue<TreeNode*> q;
        if (root == nullptr)
           return 0;

        q.push(root);
        int level = 0;
        while(!q.empty())
        {
           int size = q.size();
           for(int i = 0 ; i < size ; i++)
           {
              TreeNode* n = q.front();
              q.pop();
           }
           level++;
        }

        return level;
    }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
}