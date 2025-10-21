#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Check if Tree is Balanced

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

bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;
}

int maxDepth(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int r = maxDepth(root->right);
    int l = maxDepth(root->left);
    if(r==-1 || l==-1) {
        return -1;
    }
    if(abs(l-r) > 1) {
        return -1;
    }
    return 1+max(l,r);
}

int main() {
    return 0;
}