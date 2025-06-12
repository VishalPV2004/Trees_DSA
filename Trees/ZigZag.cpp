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

vector<int> revers(vector<int> v)
{
    reverse(v.begin(),v.end());
    return v;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL)
          return ans;
    queue<TreeNode*> q;
    q.push(root);
    int flag = 1;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> list;
        for(int i = 0 ; i < size ; i++)
        {
            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
                
            if (node->right != NULL)
                q.push(node->right);
            list.push_back(node->val);
        }
        if (flag == 1)
        ans.push_back(list);
        else
        ans.push_back(revers(list));

        flag = ~flag;
    }

    return ans;
}

int main()
{
   struct TreeNode * root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   
   Solution obj;
   int k = obj.diameterOfBinaryTree(root);
   cout<<k;
}