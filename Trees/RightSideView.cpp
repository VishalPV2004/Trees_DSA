#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
           int size = q.size();
           for(int i = 0 ; i < size ; i++)
           {
              TreeNode* node = q.front();
              q.pop();
              if (i == size - 1)
                 ans.push_back(node->val); 
              
              if (node->left != NULL)
              {
                  q.push(node->left);
              }

              if (node->right != NULL)
              {
                  q.push(node->right);
              }
           }
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    Solution obj;
    vector<int> boundary = obj.boundaryTraversal(root);
    
    for (int val : boundary) {
        cout << val << " ";
    }

    return 0;
}
