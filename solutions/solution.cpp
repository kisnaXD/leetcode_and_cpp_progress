#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Balanced Parantheses

bool balancedParantheses(string s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else if(s[i] == '}') {
            if(st.empty() || st.top() != '{') {
                return false;
            }
            st.pop();
        } else if(s[i] == ')') {
            if(st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        } else if(s[i] == ']') {
            if(st.empty() || st.top() != '[') {
                return false;
            }
            st.pop();
        }
    }
    if(st.size() == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s = "((((()))))";
    cout << balancedParantheses(s);
    return 0;
}