#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Pair {
    Node* node;
    int num;
    Pair(Node* n, int val) {
        node = n;
        num = val;
    }
};

class Solution {
public:
    vector<vector<int>> treeTraversal(Node* root) {
        vector<int> inorder, preorder, postorder;
        vector<vector<int>> all;

        if (root == NULL)
            return {inorder, postorder, preorder};

        stack<Pair*> st;
        st.push(new Pair(root, 1));

        while (!st.empty()) {
            Pair* it = st.top();
            st.pop();

            if (it->num == 1) {
                preorder.push_back(it->node->data);
                it->num++;
                st.push(it);
                if (it->node->left != NULL)
                    st.push(new Pair(it->node->left, 1));
            }
            else if (it->num == 2) {
                inorder.push_back(it->node->data);
                it->num++;
                st.push(it);
                if (it->node->right != NULL)
                    st.push(new Pair(it->node->right, 1));
            }
            else {
                postorder.push_back(it->node->data);
            }
        }

        all.push_back(inorder);
        all.push_back(postorder);
        all.push_back(preorder);

        return all;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;
    vector<vector<int>> result = sol.treeTraversal(root);

    vector<string> names = {"Inorder", "Postorder", "Preorder"};
    for (int i = 0; i < 3; ++i) {
        cout << names[i] << ": ";
        for (int val : result[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
