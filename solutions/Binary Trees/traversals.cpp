#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// All Traversals

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

vector<int> preorderRecursive(TreeNode* root, vector<int> v) {
    if(root) {
        v.push_back(root->val);
        v = preorderRecursive(root->left, v);
        v = preorderRecursive(root->right, v);
        return v;
    } else return v;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> v;
    v = preorderRecursive(root, v);
    return v;
}

vector<int> inorderRecursive(TreeNode* root, vector<int> v) {
    if(root) {
        v = inorderRecursive(root->left, v);
        v.push_back(root->val);
        v = inorderRecursive(root->right, v);
        return v;
    } else return v;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    v = inorderRecursive(root, v);
    return v;
}

vector<int> postorderRecursive(TreeNode* root, vector<int> v) {
    if(root) {
        v = postorderRecursive(root->left, v);
        v = postorderRecursive(root->right, v);
        v.push_back(root->val);
        return v;
    } else return v;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> v;
    v = postorderRecursive(root, v);
    return v;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) {
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for(int i=0; i<size; i++) {
            TreeNode* n = q.front();
            q.pop();
            if(n->left != NULL) {
                q.push(n->left);
            }
            if(n->right != NULL) {
                q.push(n->right);
            }
            level.push_back(n->val);
        }
        ans.push_back(level);
    }
    return ans;
}

vector<int> iterativePreorder(TreeNode* root) {
    vector<int> preorder;
    if(root == NULL) {
        return preorder;
    }
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()) {
        root = st.top();
        st.pop();
        preorder.push_back(root->val);
        if(root->right != NULL) {
            st.push(root->right);
        }
        if(root->left != NULL) {
            st.push(root->left);
        }
    }
    return preorder;
}

vector<int> iterativeInorder(TreeNode* root) {
    vector<int> inorder;
    if(root == NULL) {
        return inorder;
    }
    stack<TreeNode*> st;
    TreeNode* n = root;
    while(true) {
        if(n!= NULL) {
            st.push(n);
            n = n->left;
        } else {
            if(st.empty()) {
                break;
            }
            n = st.top();
            st.pop();
            inorder.push_back(n->val);
            n = n->right;
        }
    }
    return inorder;
}

vector<int> iterativePostorderTwoStacks(TreeNode* root) {
    TreeNode* n = root;
    vector<int> postorder;
    if(n == NULL) {
        return postorder;
    }
    stack<TreeNode*> st1, st2;
    st1.push(n);
    while(!st1.empty()) {
        n = st1.top();
        st1.pop();
        if(n->left != NULL) {
            st1.push(n->left);
        }
        st2.push(n);
        if(n->right != NULL) {
            st2.push(n->right);
        }
    }
    return postorder;
}

vector<int> iterativePostorderSingleStack(TreeNode* root) {
    vector<int> postorder;
    if(root == NULL) {
        return postorder;
    }
    stack<TreeNode*> st;
    TreeNode* mover = root;
    while(mover != NULL || !st.empty()) {
        if(mover != NULL) {
            st.push(mover);
            mover = mover->left;
        } else {
            TreeNode* t = st.top()->right;
            if(t!=NULL) {
                mover = t;
            } else {
                t = st.top();
                st.pop();
                postorder.push_back(t->val);
                while(!st.empty() && t == st.top()->right) {
                    t = st.top();
                    st.pop();
                    postorder.push_back(t->val);
                }
            }
        }
    }
    return postorder;
}

int main() {
    return 0;
}