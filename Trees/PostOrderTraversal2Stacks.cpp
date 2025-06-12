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

    vector<int> postorderTraversal(Node* root) {
        
        vector<int> ans;
        if (root == NULL)
           return ans;
        
        stack<Node*> st1;
        stack<Node*> st2;

        st1.push(root);

        while(!st1.empty())
        {
            Node* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left != NULL)
               st1.push(node->left);
            if (node->right != NULL)
               st1.push(node->right);
        }

        while(!st2.empty())
        {
            ans.push_back(st2.top()->data);
            st2.pop();
        }

        return ans;
    }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   
   vector<int> ans = postorderTraversal(root);
   for(int i : ans)
      cout<<i;
}