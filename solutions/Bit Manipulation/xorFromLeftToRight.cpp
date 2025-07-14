#include <bits/stdc++.h>
using namespace std;

// XOR From Left to Right

int xorFromOneToN(int N) {
    if(N%4 == 0) {
        return N;
    } else if (N%4 == 1) {
        return 1;
    } else if (N%4 == 2) {
        return N+1;
    } else {
        return 0;
    }
}

int xorFromLToR(int L, int R) {
    return xorFromOneToN(L-1) ^ xorFromOneToN(R);
}

int main() {
    int L = 4;
    int R = 7;
    cout << xorFromLToR(L, R);
    return 0;
}