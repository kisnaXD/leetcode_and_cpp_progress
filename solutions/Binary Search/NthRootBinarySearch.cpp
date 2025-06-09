#include <bits/stdc++.h>
using namespace std;

// Nth Root using Binary Search

int powerCalc(int a, int b) {
    int p = a;
    for(int i=1; i<b; i++) {
        a = a*p;
    }
    return a;
}

int nRootBS(int N, int M) {
    int low = 1;
    int high = M;
    int ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        int p = powerCalc(mid, N);
        if(p == M) {
            ans = mid;
            return ans;
        } else if(p > M) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int root27 = nRootBS(3, 27);
    cout << root27;
}
