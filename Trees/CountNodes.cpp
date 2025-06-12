class Solution {
public:
    int ct = 0;

    void count(TreeNode* root)
    {
        if (root == NULL)
           return ;
        
        ct++;
        count(root->left);
        count(root->right);
    }
    int countNodes(TreeNode* root) {
        count(root);
        return ct;
    }
};