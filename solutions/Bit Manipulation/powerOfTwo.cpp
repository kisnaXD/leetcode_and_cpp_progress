#include <bits/stdc++.h>
using namespace std;

// Check if a Number is a power of Two or Not

bool isPowerOfTwo(int N) {
    if(N==0) return false;
    if(N==INT_MIN) return false;
    return !(N & (N-1));
}

int main() {
    int x = 18;
    cout << isPowerOfTwo(x);
    return 0;
}