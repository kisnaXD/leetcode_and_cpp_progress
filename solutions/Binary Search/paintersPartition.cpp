#include <bits/stdc++.h>
using namespace std;

// Book Allocation 

int paintSplit(vector<int> &arr, int N, int m, int s) {
    int k = 1, cu = 0;
    for(int i=0; i<N; i++) {
        if(arr[i] + cu > m) { 
            cu = arr[i];
            k++;
        } else {
            cu+=arr[i];
        }
    }
    return k;
}

int paintersPartition(vector<int> &arr, int N, int s) {
    int max=0,sum=arr[0];
    for(int i=0; i<N; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        sum+=arr[i];
    }
    while(max<=sum) {
        int mid = (max+sum)/2;
        int k = paintSplit(arr, N, mid, s);
        if(k  > s) {
            max = mid + 1;
        } else {
            sum = mid - 1;
        }
    }
    return max;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    int pp = paintersPartition(v, 5, 3);
    cout << pp;
}
