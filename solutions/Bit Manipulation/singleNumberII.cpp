#include <bits/stdc++.h>
using namespace std;

// Single Number II

int singleNumber(vector<int> &arr, int N) {
    int ones = 0;
    int twos = 0;
    for(int i=0; i<N; i++) {
        ones = (ones^arr[i]) & (~twos);
        twos = (twos^arr[i]) & (~ones);
    }
    return ones;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);

    cout << singleNumber(v, 10);
    return 0;
}