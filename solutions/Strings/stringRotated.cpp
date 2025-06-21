#include <bits/stdc++.h>
using namespace std;

// Check if a string can be obtained by rotating another one

bool stringRotated(string s, string goal) {
    if(s.length() != goal.length()) {
            return false;
    }
    string newStr = s + s;
    if(newStr.find(goal) != string::npos) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s1 = "abcde";
    string s2 = "abced";
    bool ans = stringRotated(s1, s2);
    cout << ans;  
}
