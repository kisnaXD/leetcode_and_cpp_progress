#include <bits/stdc++.h>
using namespace std;

// Second Largest Element

int secondLargest(vector <int> &arr, int n) {
    int L = arr[0];
    int sL = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] < L && arr[i] > sL) {
            sL = arr[i];
        } else if(arr[i] > L) {
            sL = L;
            L = arr[i];
        }
    }
    return sL;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    cout << secondLargest(v, 5);
}