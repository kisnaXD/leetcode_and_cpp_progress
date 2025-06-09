#include <bits/stdc++.h>
using namespace std;

// Square Root using Binary Search

int sqRootBS(int N) {
    int low = 1;
    int high = N;
    int ans = INT_MIN; 
    while(low<=high) {
        int mid = (low+high)/2;
        if(mid*mid <= N) {
            ans = mid;
            low = mid +1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int root7 = sqRootBS(7);
    cout << root7;
}
