#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Diameter of a Binary Tree

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

int height(TreeNode* root, int &d) {
    if(root == NULL) {
        return 0;
    }
    int l = height(root->left, d);
    int r = height(root->right, d);
    d = max(d, r+l);
    return 1+max(l,r);
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int d = 0;
    height(root, d);
    return d;
}

int main() {
    return 0;
}