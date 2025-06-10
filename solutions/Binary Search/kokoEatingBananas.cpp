#include <bits/stdc++.h>
using namespace std;

// Koko Eating Bananas

int hours (vector<int> &arr, int N, int a) {
    int h = 0;
    for(int i=0; i<N; i++) {
        if(arr[i]%a != 0) {
            h+=arr[i]/a + 1;
        } else {
            h+=arr[i]/a;
        }
    }
    return h;
}

int kokoEatingBananas(vector<int> &arr, int N, int K) {
    int maxi = arr[0];
    for(int i=1; i<N; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    int low = 1, high = maxi, ans = maxi;
    while(low<=high) {
        int mid = (low+high)/2;
        int h = hours(arr, N, mid);
        if(h == K) {
            return mid;
        } else if (h<K) { 
            ans = ans > mid ? mid : ans;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(9);
    v.push_back(7);
    int koko = kokoEatingBananas(v, 4, 8);
    cout << koko;
}
