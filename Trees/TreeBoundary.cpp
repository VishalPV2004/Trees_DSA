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
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }

    void addLeft(TreeNode* node, vector<int>& res) {
        TreeNode* cur = node->left;
        while (cur) {
            if (!isLeaf(cur))
                res.push_back(cur->data);
            cur = (cur->left) ? cur->left : cur->right;
        }
    }

    void addRight(TreeNode* node, vector<int>& res) {
        TreeNode* cur = node->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur))
                tmp.push_back(cur->data);
            cur = (cur->right) ? cur->right : cur->left;
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
            res.push_back(tmp[i]);
    }

    void addLeaves(TreeNode* node, vector<int>& res) {
        if (isLeaf(node)) {
            res.push_back(node->data);
            return;
        }
        if (node->left) addLeaves(node->left, res);
        if (node->right) addLeaves(node->right, res);
    }

    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeft(root, res);
        addLeaves(root, res);
        addRight(root, res);
        return res;
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
