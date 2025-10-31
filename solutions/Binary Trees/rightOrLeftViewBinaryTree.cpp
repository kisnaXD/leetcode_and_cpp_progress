#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Right/Left View of a Binary Tree

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

void recursion(TreeNode* root, int level, vector<int> &res) {
    if(root == NULL) {
        return;
    }
    if(res.size() == level) {
        res.push_back(root->val);
    }
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;
}

int main() {
    return 0;
}