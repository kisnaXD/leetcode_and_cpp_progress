#include <bits/stdc++.h>
using namespace std;

// Check if Two Strings are Isomorphic

bool isIsomorphic(string s, string t) {
    unordered_map<char , char> map1;
    unordered_map<char , char> map2;
    int n = s.length();
    for(int i = 0; i < n; ++i){
        char key = s[i];
        char value = t[i];
        if(!(map1.count(key))) {
            map1[key] = value;
        } else if(!(map1[key] == value)) {
            return false;
        }
        if(!(map2.count(value))) {
            map2[value] = key;
        } else if(!(map2[value] == key)) {
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "egg";
    string s2 = "oaa";
    bool ans = isIsomorphic(s1, s2);
    cout << ans;  
}
