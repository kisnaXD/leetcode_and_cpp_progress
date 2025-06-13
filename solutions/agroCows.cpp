#include <bits/stdc++.h>
using namespace std;

// Aggressive Cows

bool placementPossible(vector<int> &arr, int N, int d, int C) {
    int k = 1, cu = 0;
    for(int i=1; i<N; i++) {
        if(arr[i]-arr[cu] >= d) {
            k+=1;
            cu = i;
        }
    }
    if(k>=C) {
        return true;
    } else {
        return false;
    }
}

int aggressiveCows(vector<int> &arr, int N, int C) {
    int min=0, max=0;
    for(int i=1; i<N; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    int high = max-min;
    int ans = -1;
    int low = 1;
    while(low<=high) { 
        int mid = (low + high)/2;
        bool ret = placementPossible(arr, N, mid, C);
        if(ret) {
            ans = mid;
            low = mid +1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(9);
    v.push_back(10);
    int agroCow = aggressiveCows(v, 6, 4);
    cout << agroCow;
}
