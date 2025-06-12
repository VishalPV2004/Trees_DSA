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
    vector<int> topView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mp; // horizontal distance -> node->data
        queue<pair<Node*, int>> q; // Node pointer + horizontal distance

        q.push({root, 0});

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* node = temp.first;
            int hd = temp.second;

            if (mp.find(hd) == mp.end()) {
                mp[hd] = node->data;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        for (auto it : mp) {
            ans.push_back(it.second);
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
