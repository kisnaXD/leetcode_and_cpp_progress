#include <bits/stdc++.h>
using namespace std;

// Maximum Number of Consecutive Ones

int maxConsecutiveOnes(vector <int> &arr, int N) {
    int c = 0, maxC = -1;
    for(int i = 0; i<N; i++) {
        if(arr[i] == 1) {
            c+=1;
        } else {
            c = 0;
            maxC = c>maxC ? c : maxC;
        }
        maxC = c>maxC ? c : maxC;
    }
    return maxC;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(6);
    int maxConsecutiveOnesR = maxConsecutiveOnes(v, 5);
    cout << maxConsecutiveOnesR << endl;
}