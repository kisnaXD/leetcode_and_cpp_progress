#include <bits/stdc++.h>
using namespace std;

// Number of Sub Arrays with XOR K

int numberOfSubArraysWithXORK(vector<int> arr, int N, int K) {
    int preXOR = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int counter = 1;
    for(int i=0; i<N; i++) {
        preXOR = preXOR ^ arr[i];
        int req = preXOR ^ K;
        if(mpp.find(req) != mpp.end()) {
            counter+= mpp[req];
        }
        mpp[preXOR] +=1;
    }
    return counter;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    int ans = numberOfSubArraysWithXORK(v, 5, 6);
    cout << ans;
    return 0;
}