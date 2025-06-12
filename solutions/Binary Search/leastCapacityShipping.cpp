#include <bits/stdc++.h>
using namespace std;

// Least capacity to ship within D Days

int daysCalculator(vector<int> &arr, int N, int c) {
    int cap=0;
    int days=1;
    for(int i=0; i<N; i++) {
        if(cap+arr[i] > c) {
            days+=1;
            cap = arr[i];
        } else {
            cap+=arr[i];
        }
    }
    return days;
}

int leastCapacity(vector<int> &arr, int N, int t) {
    int min=0, max=0, ans=-1;
    for(int i=0; i<N; i++) {
        if(min < arr[i]) {
            min = arr[i];
        }
        max+=arr[i];
    }
    while(min <= max) {
        int mid = (min+max)/2;
        int days = daysCalculator(arr, N, mid);
        if(days <= t) {
            ans = mid;
            max = mid - 1;
        } else min = mid + 1;
    }
    return ans;
}
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    int lCap = leastCapacity(v, 10, 5);
    cout << lCap;
}
