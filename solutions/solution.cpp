#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Largest Rectangle in Histogram

int largestRectangleArea(vector<int>& arr) {
    stack<int> st;
    int maxArea = 0;
    int N = arr.size();
    for(int i=0; i<N; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            int el = st.top();
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int area = arr[el] * (nse - pse - 1);
            maxArea = max(area, maxArea);
        }
        st.push(i);
    }
    while(!st.empty()) {
        int el = st.top();
        st.pop();
        int nse = N;
        int pse = st.empty() ? -1 : st.top();
        int area = arr[el] * (nse - pse - 1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int main() {
    return 0;
}