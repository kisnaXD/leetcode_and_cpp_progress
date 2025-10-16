#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    int N = arr.size();
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<N; i++) {
        if(!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) {
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}

int main() {
    return 0;
}