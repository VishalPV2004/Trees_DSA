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
    bool checkSymmetry(TreeNode* left,TreeNode* right)
    {
        if (left == NULL && right == NULL)
           return true;
        
        if (left == NULL || right == NULL)
           return false;
        
        return (left->val == right->val) &&
                checkSymmetry(left->left, right->right) &&
                checkSymmetry(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL || checkSymmetry(root->left,root->right))
            return true;
        return false;
        
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
