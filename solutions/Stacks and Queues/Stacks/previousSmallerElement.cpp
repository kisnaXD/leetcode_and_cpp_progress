#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Previous Smaller Element

vector<int> previousSmallerElement(vector<int> &arr, int N) {
    vector<int> ans(N);
    stack<int> st;
    for(int i=0; i<N; i++) {
        if(st.empty()) {
            st.push(arr[i]);
            ans[i] = -1;
        } else {
            if(arr[i] > st.top()) {
                ans[i] = st.top();
                st.push(arr[i]);
            } else {
                while(!st.empty() && arr[i] <= st.top()) {
                    st.pop();
                }
                if(st.empty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.top();
                }
                st.push(arr[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(7);
    v.push_back(2);
    v.push_back(5);
    v.push_back(4);
    vector<int> ans = previousSmallerElement(v, 4);
    for(int i: ans) {
        cout << i << " ";
    }
    return 0;
}