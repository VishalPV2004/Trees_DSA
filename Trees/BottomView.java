class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        map<int, int> mp; // hd -> node->data
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<Node*, int> p = q.front();
            q.pop();

            Node* n = p.first;
            int hd = p.second;

            mp[hd] = n->data; // overwrite for bottom view

            if (n->left != nullptr)
                q.push({n->left, hd - 1});
            if (n->right != nullptr)
                q.push({n->right, hd + 1});
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
