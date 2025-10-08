#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Remove K Digits

string removeKdigits(string s, int k) {
    stack<char> st;
    string res = "";
    for(int i=0; i<s.length(); i++) {
        while(!st.empty() && k>0 && (st.top() - '0') > (s[i] - '0')) {
            st.pop();
            k-=1;
        }
        st.push(s[i]);
    }
    while(k>0) {
        st.pop();
        k-=1;
    }
    if(st.empty()) {
        return "0";
    }
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    while(res.size() > 0 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    if(res.empty()) {
        return "0";
    }
    
    return res;
}

int main() {
    return 0;
}