#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Vertical Order Traversal of Binary Tree

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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while(!todo.empty()) {
        auto p = todo.front();
        todo.pop();
        TreeNode* n = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(n->val);
        if(n->left != NULL) {
            todo.push({n->left, {x-1, y+1}});
        }
        if(n->right != NULL) {
            todo.push({n->right, {x+1, y+1}});
        }
    }
    for(auto p: nodes) {
        vector<int> col;
        for(auto q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {
    return 0;
}