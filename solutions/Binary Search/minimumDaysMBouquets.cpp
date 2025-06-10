#include <bits/stdc++.h>
using namespace std;

// Minimum Days to make M Bouquets

bool possibility(vector<int> &arr, int N, int M, int K, int day) {
    int c=0, n=0;
    for(int i=0; i<N; i++) {
        if(arr[i] <= day) {
            c++;
        } else {
            n+= c/K;
            c = 0;
        }
    }
    n+=c/K;
    if(n>=M) return true;
    else return false;
}

int minimumDays(vector<int> &arr, int N, int M, int K) {
    int mini=INT_MAX, maxi=INT_MIN;
    for(int i=0; i<N; i++) {
        if(arr[i] < mini) {
            mini=arr[i];
        }
        if(arr[i] > maxi) {
            maxi=arr[i];
        }
    }
    int minDays=INT_MAX;
    while(mini<=maxi) {
        int mid = (mini+maxi)/2;
        bool days = possibility(arr, N, M, K, mid);
        if(days && mid<minDays) {
            minDays = mid;
            maxi = mid - 1;
        } else {
            mini = mid + 1;
        }
    }
    return minDays;
}

int main() {
    vector<int> v;
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(7);
    v.push_back(13);
    v.push_back(11);
    v.push_back(12);
    v.push_back(7);
    int miniD = minimumDays(v, 8, 2,3);
    cout << miniD;
}
