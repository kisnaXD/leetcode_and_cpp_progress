#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Prefix Infix and Postfix Conversions

int priority(char x) {
    if(x=='+' || x=='-') {
        return 1;
    } else if(x == '*' || x == '/') {
        return 2;
    } else if(x == '^') {
        return 3;
    } else {
        return -1;
    }
}

string reverseString(string s) {
    for(int i=0; i<s.length()/2; i++) {
        char t = s[i];
        s[i] = s[s.length() - 1 - i];
        s[s.length() - 1 - i] = t;
    }
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '(') {
            s[i] = ')';
        } else if(s[i] == ')') {
            s[i] = '(';
        }
    }
    return s;
}

string infixToPostfix(string s) {
    int i=0;
    stack<char> st;
    string ans = "";
    while(i<s.size()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            ans += s[i];
        } else if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && priority(s[i]) < priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i+=1;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string str) {
    int i=0;
    stack<char> st;
    string ans = "";
    string s = reverseString(str);
    while(i<s.size()) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            ans += s[i];
        } else if(s[i] == '(') {
            st.push(s[i]);
        } else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i+=1;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return reverseString(ans);
}

string postfixToInfix(string s) {
    stack<string> st;
    for(int i=0; i<s.length(); i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            st.push(string(1, s[i]));
        } else {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string c = '(' + c2 + s[i] + c1 + ')';
            st.push(c);
        }
    }
    return st.top();
}

string prefixToInfix(string s) {
    stack<string> st;
    for(int i=s.length()-1; i>=0; i--) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            st.push(string(1, s[i]));
        } else {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string c = '(' + c1 + s[i] + c2 + ')';
            st.push(c);
        }
    }
    return st.top();
}

string postfixToPrefix(string s) {
    stack<string> st;
    for(int i=0; i<s.length(); i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            st.push(string(1, s[i]));
        } else {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string c = s[i] + c2 + c1;
            st.push(c);
        }
    }
    return st.top();
}

string prefixToPostfix(string s) {
    stack<string> st;
    for(int i=s.length() - 1; i>=0; i--) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            st.push(string(1, s[i]));
        } else {
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string c = c1 + c2 + s[i];
            st.push(c);
        }
    }
    return st.top();
}

int main() {
    string s = "(a+b)*(c+d)";
    cout << infixToPostfix(s) << endl;
    cout << infixToPrefix(s) << endl;
    cout << postfixToInfix(infixToPostfix(s)) << endl;
    cout << prefixToInfix(infixToPrefix(s)) << endl;
    cout << postfixToPrefix(infixToPostfix(s)) << endl;
    cout << prefixToPostfix(infixToPrefix(s)) << endl;
    return 0;
}