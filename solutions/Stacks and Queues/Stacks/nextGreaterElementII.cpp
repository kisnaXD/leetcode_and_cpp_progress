#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Next Greater Element II 

vector<int> nextGreaterElements(vector<int>& arr) {
    int N = arr.size();
    vector<int> ans(N);
    stack<int> st;
    for(int i=2*N-1; i>=0; i--) {
        int ind = i%N;
        if(i>N-1) {
            if(st.empty()) {
                st.push(arr[ind]);
            } else {
                if(st.top() > arr[ind]) {
                    st.push(arr[ind]);
                } else {
                    while(!st.empty() && st.top() <= arr[ind]) {
                        st.pop();
                    }
                    st.push(arr[ind]);
                }
            }
        } else {
            if(st.top() > arr[ind]) {
                ans[ind] = st.top();
                st.push(arr[ind]);
            } else {
                while(!st.empty() && st.top() <= arr[ind]) {
                    st.pop();
                }
                if(st.empty()) {
                    ans[ind] = -1;
                } else {
                    ans[ind] = st.top();
                }
                st.push(arr[ind]);
            }
        }
    }
    return ans;
}

int main() {
    return 0;
}