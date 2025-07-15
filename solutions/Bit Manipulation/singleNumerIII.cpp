#include <bits/stdc++.h>
using namespace std;

// Single Number III

vector<int> singleNumberIII(vector<int> &arr, int N) {
    long initialXOR = 0;
    for(int i=0; i<N; i++) {
        initialXOR = initialXOR ^ arr[i];
    }
    int firstSetBit = (initialXOR & (initialXOR - 1)) & initialXOR;
    int notSet = 0, setBit = 0;
    for(int i=0; i<N; i++) {
        if(arr[i] & firstSetBit != 0) {
            setBit = setBit ^ arr[i];
        } else {
            notSet = notSet ^ arr[i];
        }
    }
    vector<int> v;
    v.push_back(setBit);
    v.push_back(notSet);
    return v;
}

int main() {
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);

    vector<int> v1 = singleNumberIII(v, 8);
    cout << v1[0] << " " << v1[1];
    return 0;
}