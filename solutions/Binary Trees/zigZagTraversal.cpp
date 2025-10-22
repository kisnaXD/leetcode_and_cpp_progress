#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Zig Zag Traversal

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l, TreeNode* r) {
        val = v;
        left = l;
        right = r;
    }
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    bool l2r = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for(int i=0; i<size; i++) {
            TreeNode* n = q.front();
            q.pop();
            int index = l2r ? i : size - i - 1;
            level[index] = n->val;
            if(n->left != NULL) {
                q.push(n->left);
            }
            if(n->right != NULL) {
                q.push(n->right);
            }
        }
        l2r = !l2r;
        ans.push_back(level);
    }
    return ans;
}

int main() {
    return 0;
}