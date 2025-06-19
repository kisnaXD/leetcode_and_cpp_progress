#include <bits/stdc++.h>
using namespace std;

// Remove outer Paranthesis

string removeOuterParanthesis(string str, int N) {
    string r;
    int b = 0;
    for(int i=0; i<N; i++) {
        if(str[i] == '(') {
            if(b > 0) {
                r+=str[i];
            }
            b++;
        } else {
            b--;
            if(b>0) {
                r+=str[i];
            }
        }
    }
    return r;
}


int main() {
    string myStr = "(()()())(()())((()))";
    string ans = removeOuterParanthesis(myStr, myStr.size());
    cout << ans;
}
