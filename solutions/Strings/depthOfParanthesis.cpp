#include <bits/stdc++.h>
using namespace std;

// Maximum Depth of Paranthesis

int maxDepth(string str, int N) {
    int count = 0;
    int res = 0;
    for(int i = 0; i<N; i++) {
        if(str[i] == '(') {
            count++;
            res = max(count, res);
        } else if (str[i] == ')') {
            count--;
        }
    }
    return res;
}

int main() {
    string str = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(str, str.size());
}
