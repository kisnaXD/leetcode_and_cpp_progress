#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Identical Tree

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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL || q==NULL) {
        return (p==q);
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    return 0;
}