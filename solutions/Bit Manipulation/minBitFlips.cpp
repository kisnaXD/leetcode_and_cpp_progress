#include <bits/stdc++.h>
using namespace std;

// Minimum number of Bit Flips to convert from one number to the other

int minBitFlips(int start, int goal) {
    int ans = start^goal;
    int c = 0;
    for(int i=0; i<31; i++) {
        if(ans & (1<<i)) {
            c+=1;
        }
    }
    return c;
}

int main() {
    int x = 18;
    int y = 32;
    cout << minBitFlips(x, y);
    return 0;
}