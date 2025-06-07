#include <bits/stdc++.h>
using namespace std;

// Count Subarrays with Given Sum K

int countSubarraysWithGivenSum(vector<int> &arr, int N, int K) {
    int counter = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    for(int i=0; i<N; i++) {
        sum+=arr[i];
        int rem = sum - K;
        counter+=mpp[rem];
        mpp[sum]+=i;
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(-3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(-3);
    int ans = countSubarraysWithGivenSum(v, 10, 3);
    cout << ans;
    return 0;
}