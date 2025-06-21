#include <bits/stdc++.h>
using namespace std;

// Valid Anagram

bool validAnagramMap(string s1, string s2) {
    if(s1.length() != s2.length()) {
        return false;
    }
    unordered_map<char, int> mpp;
    for(auto x : s1) {
        mpp[x]++;
    }
    for(auto x : s2) {
        mpp[x]--;
    }
    for(auto x: mpp) {
        if(x.second != 0) {
            return false;
        }
    }
    return true;
}

bool validAnagramSorting(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1==s2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string s1 = "abcde";
    string s2 = "abced";
    bool ans = validAnagramMap(s1, s2);
    bool ans2 = validAnagramSorting(s1, s2);
    cout << ans << " " << ans2;  
}
