#include <bits/stdc++.h>
using namespace std;

// Missing Element both Optimal Solutions

int missingElementOptimal1(vector <int> &arr, int N) {
    int sum = N * (N+1) / 2;
    int arraySum = 0;
    for(int i=0; i<N; i++) {
        arraySum += arr[i];
    }
    return sum-arraySum;
}

int missingElementOptimal2(vector <int> &arr, int N) {
    int xor1 = 0, xor2 = 0;
    for(int i=0; i<N-1; i++) {
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ N;
    return xor2 ^ xor1;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    int missingElement = missingElementOptimal1(v, 6);
    cout << missingElement << endl;
}