#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Sum of Subarray Minimum

vector<int> findPSE(vector<int> &arr, int N) {
    stack<int> st;
    vector<int> ans(N);
    for(int i=0; i<N; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findNSE(vector<int> &arr, int N) {
    stack<int> st;
    vector<int> ans(N);
    for(int i=N-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? N : st.top();
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins(vector<int>& arr) {
    int N = arr.size();
    vector<int> nse = findNSE(arr, N);
    vector<int> pse = findPSE(arr, N);
    int total = 0;
    int mod = (int) (1e9 + 7);
    for(int i=0; i<N; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;
        total = ((total + 1LL*left*right*arr[i])%mod)%mod;
    }
    return (total+mod)%mod;
}

int main() {
    return 0;
}