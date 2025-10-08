#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Asteroid Collision

vector<int> asteroidCollision(vector<int>& arr) {
    list<int> st;
    vector<int> ans;
    int N = arr.size();
    for(int i=0; i<N; i++) {
        if(arr[i] > 0) {
            st.push_back(arr[i]);
        } else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])) {
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(arr[i])) {
                st.pop_back();
            } else if(st.empty() || st.back() < 0) {
                st.push_back(arr[i]);
            }
        }
    }
    while(!st.empty()) {
        ans.push_back(st.back());
        st.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    return 0;
}