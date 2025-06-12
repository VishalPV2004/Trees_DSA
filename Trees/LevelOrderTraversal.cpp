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

vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> list;
        if (root == NULL)
           return list;
        
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i = 0 ; i < size ; i++)
            {
                Node* node = q.front();
                q.pop();

                if (node->left != NULL)
                   q.push(node->left);
                if (node->right != NULL)
                   q.push(node->right);
                level.push_back(node->data);
            }
            list.push_back(level);
        }

        return list;
    }

int main()
{
   struct Node * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->left = new Node(6);
   root->right->right = new Node(7);
   
   vector<vector<int>> list = levelOrder(root);
   
   for(vector v : list)
   {
       for(int i : v)
       {
           cout<<i<<" ";
       }
       cout<<endl;
   }
   
   return 0;
}