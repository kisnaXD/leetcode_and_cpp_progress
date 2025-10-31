#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Symmetric Tree

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

bool isMirror(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) {
        return true;
    }
    if(p == NULL || q == NULL) {
        return false;
    }
    return (p->val == q->val) && isMirror(p->right, q->left) && isMirror(p->left, q->right);
}

bool symmetricTree(TreeNode* root) {
    return isMirror(root->left, root->right);
}

int main() {
    return 0;
}