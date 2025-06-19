#include <bits/stdc++.h>
using namespace std;

// Longest Commmon Prefix

string longestCommonPrefix(vector<string> str, int N) {
    string prefix = str[0];
    for(int i=1; i<N; i++) {
        while(str[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if(prefix.empty()) {
                return "";
            }
        }
    }
    return prefix;
}

int main() {
    string s1 = "leetcode";
    string s2 = "leet";
    string s3 = "le";
    vector<string> s;
    s.push_back(s1);
    s.push_back(s2);
    s.push_back(s3);
    string ans = longestCommonPrefix(s, 3);
    cout << ans;  
}
