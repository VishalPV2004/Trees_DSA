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

vector<int> inorderTraversal(TreeNode* root) 
   {
         vector<int> ans;
         if (root == NULL)
            return ans;
         
         stack<TreeNode*> st;
         TreeNode* node = root;
         while(root != NULL)
         {
            if(node != NULL)
            {
               st.push(node);
               node = node->left;
            }
            else
            {
               if(st.empty())
                  break;
            
               node = st.top();
               st.pop();
               ans.push_back(node->val);
               node = node->right;
            }
        }
        return ans;
   }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
}