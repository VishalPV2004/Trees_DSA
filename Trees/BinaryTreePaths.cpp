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
    void getAllPaths(TreeNode* root, string s, vector<string>& ans)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(s);
            return;
        }

        if (root->left != nullptr)
         {
            getAllPaths(root->left,s+"->"+to_string(root->left->val),ans);
         }
        if (root->right != nullptr)
        {
            getAllPaths(root->right,s+"->"+to_string(root->right->val),ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s;
        s = s + to_string(root->val);
        getAllPaths(root,s,ans);

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
