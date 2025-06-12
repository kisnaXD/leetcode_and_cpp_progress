#include <bits/stdc++.h>
using namespace std;

// Smallest Divisor with a given threshhold

bool divisorSum(vector<int> &arr, int N, int d, int t) {
    int c = 0;
    for(int i=0; i<N; i++) {
        if(arr[i]%d == 0) {
            c+=arr[i]/d;
        } else {
            c+=arr[i]/d+1;
        }
    }
    if(c<=t) return true;
    else return false;
}

int smallestDivisor(vector<int> &arr, int N, int t) {
    int max = 0;
    for(int i=1; i<N; i++) {
        if(arr[i] > arr[max]) {
            max = i;
        }
    }
    int low = 1;
    int ans = -1;
    max = arr[max];
    while(low<=max) {
        int mid = (low+max)/2;
        if(divisorSum(arr, N, mid, t)) {
            ans = mid;
            max = mid -1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(9);
    int smallestDivisorAns = smallestDivisor(v, 4, 6);
    cout << smallestDivisorAns;
}
