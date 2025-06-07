#include <bits/stdc++.h>
using namespace std;

// Leaders in an Array

vector<int> leadersInAnArray(vector<int> &arr, int N) {
    vector<int> v;
    int maxi = INT_MIN;
    for(int i = N-1; i>=0; i--) {
        if(arr[i] > maxi) {
            v.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return v;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    vector<int> ans = leadersInAnArray(v, 7);
    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}