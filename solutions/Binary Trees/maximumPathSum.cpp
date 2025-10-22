#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Maximum Path Sum

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

int maxSum(TreeNode* root, int &maxi) {
    if(root == NULL) {
        return 0;
    }
    int l = max(0, maxSum(root->left, maxi));
    int r = max(0, maxSum(root->right, maxi));
    maxi = max(maxi, l+r+root->val);
    return max(l,r) + root->val;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}

int main() {
    return 0;
}