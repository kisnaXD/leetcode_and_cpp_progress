#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Top View of a Binary Tree

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

vector<int> topviewBinaryTree(TreeNode* root) {
    vector<int> ans;
    queue<pair<TreeNode*, int>> q;
    map<int, int> mpp;
    if(root == NULL) {
        return ans;
    }
    q.push({root, 0});
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* n = it.first;
        int line = it.second;
        if(mpp.find(line) == mpp.end()) {
            mpp[line] = n->val;
        }
        if(n->left != NULL) {
            q.push({n->left, line-1});
        }
        if(n->right != NULL) {
            q.push({n->right, line+1});
        }
    }
    for(auto it: mpp) {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
    return 0;
}