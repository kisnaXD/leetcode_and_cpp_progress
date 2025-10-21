#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Maximum Height of a Binary Tree

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

int maxDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }

    int r = maxDepth(root->right);
    int l = maxDepth(root->left);

    return 1+max(r,l);
}

int main() {
    return 0;
}