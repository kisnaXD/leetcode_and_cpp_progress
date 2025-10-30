#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Boundary Traversal of Binary Tree

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

void leftBoundary(TreeNode* root, vector<int> &res) {
    TreeNode* mover = root->left;
    while(mover!=NULL) {
        if(!isLeaf(mover)) {
            res.push_back(mover->val);
        }
        if(mover->left!=NULL) {
            mover = mover->left;
        } else {
            mover = mover->right;
        }
    }
}

void rightBoundary(TreeNode* root, vector<int> &res) {
    TreeNode* mover = root;
    vector<int> t;
    while(mover!=NULL) {
        if(!isLeaf(mover)) {
            t.push_back(mover->val);
        }
        if(mover->right != NULL) {
            mover = mover->right;
        } else {
            mover = mover->left;
        }
    }
}

bool isLeaf(TreeNode* root) {
    return (root->left == root->right == NULL);
}

void leaves(TreeNode* root, vector<int> &res) {
    if(isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    if(root->left != NULL) {
        leaves(root->left, res);
    }
    if(root->right != NULL) {
        leaves(root->right, res);
    }
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    if(!isLeaf(root)) {
        ans.push_back(root->val);
    }
    leftBoundary(root, ans);
    leaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}

int main() {
    return 0;
}