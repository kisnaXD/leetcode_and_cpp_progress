#include <bits/stdc++.h>
using namespace std;

// Count and Say

string describe(string &s) {
    string res = "";
    int c = 1;

    for(int i=1; i<s.length(); i++) {
        if(s[i] == s[i-1]) {
            c++;
        } else {
            res+= to_string(c) + s[i-1];
            c = 1;
        }
    }
    res += to_string(c) + s.back();
    return res;
}

string countAndSay(int n) {
    string result = "1";
    for(int i=1; i<n; i++) {
        result = describe(result);
    }
    return result;
}

int main() {
    string answer = countAndSay(7);
    cout << answer;
    return 0;
}