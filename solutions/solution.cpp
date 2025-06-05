#include <bits/stdc++.h>
using namespace std;

// Maximum Product Subarray

int maximumProductSubArray(vector<int> &arr, int N) {
    int pre=1, suff=1, maxS = INT_MIN;
    for(int i=0; i<N; i++) {
        pre = pre * arr[i];
        suff = suff * arr[N-i-1];
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        maxS = maxS > pre ? maxS : pre;
        maxS = maxS > suff ? maxS : suff;
    }
    return maxS;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    int maxS = maximumProductSubArray(v,5);
    cout << maxS;
}
