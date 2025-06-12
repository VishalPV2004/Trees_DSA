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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (root == nullptr)
           return;
        
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = prev;
        prev = root;
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
    TreeNode* node1 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(8);
    TreeNode* soln = obj.lowestCommonAncestor(root,node1,node2);
    cout<<soln;

    return 0;
}
