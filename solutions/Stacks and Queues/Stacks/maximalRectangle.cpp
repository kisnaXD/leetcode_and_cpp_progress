#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Maximal Rectangle

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
int maximalRectangle(vector<vector<char>>& mat) {
    int N = mat.size();
    int M = N!=0 ? mat[0].size() : 0;
    vector<vector<int>> pSum(N, vector<int>(M));
    int maxArea = 0;
    for(int j=0; j<M; j++) {
        int sum = 0;
        for(int i=0; i<N; i++) {
            sum+=mat[i][j] - '0';
            if(mat[i][j] == '0') {
                sum = 0;
            }
            pSum[i][j] = sum;
        }
    }
    for(int i=0; i<N; i++) {
        maxArea = max(maxArea, largestRectangleArea(pSum[i]));
    }
    return maxArea;
}

int main() {
    return 0;
}