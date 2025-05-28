#include <bits/stdc++.h>
using namespace std;

// Longest Consecutive Sequence in an Array (Google Question)

int longestConsecutiveSequence(vector<int> &arr, int N) {
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<N; i++) {
        st.insert(arr[i]);
    }
    for(auto it: st) {
        if(st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                cnt+=1;
                x+=1;
            }
            longest = longest<cnt ? cnt : longest;
        }
    }
    return longest;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    int longestConsi = longestConsecutiveSequence(v, 7);
    cout << longestConsi;
}