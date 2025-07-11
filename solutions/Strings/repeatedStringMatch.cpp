#include <bits/stdc++.h>
using namespace std;

// Repeated String Match

int repeatedStringMatch(string a, string b) {
    int q = 1;
    string s = a;
    for(; s.length() < b.length(); q++) {
        s+=a;
    }
    if(s.find(b) != string::npos) {
        return q;
    }
    s+=a;
    if(s.find(b) != string::npos) {
        return q+1;
    }
    return -1;
}

int main() {
    string a = "abcd";
    string b = "bcdabcdab";
    int answer = repeatedStringMatch(a, b);
    cout << answer;
    return 0;
}