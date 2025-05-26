#include <bits/stdc++.h>
using namespace std;

// Number that occurs only once

int numberThatOccursOnce(vector <int> &arr, int N) {
    int x = 0;
    for(int i=0; i<N; i++) {
        x = x ^ arr[i];
    }
    return x;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    int numberThatOccursOnceOnly = numberThatOccursOnce(v, 5);
    cout << numberThatOccursOnceOnly << endl;
}