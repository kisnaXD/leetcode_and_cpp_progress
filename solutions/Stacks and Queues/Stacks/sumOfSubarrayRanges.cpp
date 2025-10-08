#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Sum of Subarray Ranges

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

long long sumSubarrayMins(vector<int>& arr) {
    int N = arr.size();
    vector<int> nse = findNSE(arr, N);
    vector<int> pse = findPSE(arr, N);
    long long total = 0;
    for(int i=0; i<N; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;
        long long freq = 1LL * left * right;
        long long val = 1LL * freq * arr[i];
        total += val;
    }
    return total;
}

vector<int> findPGE(vector<int> &arr, int N) {
    stack<int> st;
    vector<int> ans(N);
    for(int i=0; i<N; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findNGE(vector<int> &arr, int N) {
    stack<int> st;
    vector<int> ans(N);
    for(int i=N-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? N : st.top();
        st.push(i);
    }
    return ans;
}

long long sumSubarrayMax(vector<int>& arr) {
    int N = arr.size();
    vector<int> nge = findNGE(arr, N);
    vector<int> pge = findPGE(arr, N);
    long long total = 0;
    for(int i=0; i<N; i++) {
        int left = i - pge[i];
        int right = nge[i] - i;
        long long freq = 1LL * left * right;
        long long val = (freq*arr[i]*1LL);
        total += val;
    }
    return total;
}

long long subArrayRanges(vector<int>& arr) {
    long long minSums = sumSubarrayMins(arr);
    long long maxSums = sumSubarrayMax(arr);
    return -1*minSums + maxSums;
}

int main() {
    return 0;
}