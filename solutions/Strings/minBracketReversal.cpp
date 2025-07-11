#include <bits/stdc++.h>
using namespace std;

// Minimum Number of Bracket Reversals Required to make a Paranthesis String Valid

int minBracketReversals(string s, int N) {
    int openBrackets = 0;
    int minReq = 0;
    for(int i=0; i<N; i++) {
        char c = s[i];
        if(c == '(') {
            openBrackets+=1;
        } else {
            if(openBrackets == 0) {
                minReq+=1;
            } else {
                openBrackets -=1;
            }
        }
    }
    minReq += openBrackets;
    return minReq;
}

int main() {
    string s = "(()()))";
    int answer = minBracketReversals(s, 7);
    cout << answer;
    return 0;
}