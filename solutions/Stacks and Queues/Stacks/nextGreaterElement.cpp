#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Next Greater Element

vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
    unordered_map<int, int> ngeMap; 
    stack<int> st;
    for (int i = b.size() - 1; i >= 0; i--) {
        while (!st.empty() && b[i] >= st.top()) {
            st.pop();
        }
        ngeMap[b[i]] = st.empty() ? -1 : st.top();
        st.push(b[i]);
    }
    vector<int> ans;
    for (int num : a) {
        ans.push_back(ngeMap[num]);
    }
    return ans;
}

int main() {
    return 0;
}