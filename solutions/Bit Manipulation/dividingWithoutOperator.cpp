#include <bits/stdc++.h>
using namespace std;

// Dividing without // Operator

int division(int dividend, int divisor) {
    if(dividend == divisor) {
        return 1;
    } else if(dividend == 0) {
        return 0;
    }
    bool signPos = true;
    if(dividend > 0 && divisor < 0) {
        signPos = false;
    } else if (dividend < 0 && divisor > 0) {
        signPos = false;
    }
    int n = abs(dividend);
    int m = abs(divisor);
    long ans = 0;
    while(n>=m) {
        int c = 0;
        while(n>=(m<<(c+1))) {
            c++;
        }
        ans += 1<<c;
        n-=m<<c;
    }
    if(ans>=INT_MAX && signPos) {
        return INT_MAX;
    } else if(ans>=INT_MAX && !signPos) {
        return INT_MIN;
    }
    return (int)ans;
}

int main() {
    int L = 22;
    int R = 7;
    cout << division(L, R);
    return 0;
}