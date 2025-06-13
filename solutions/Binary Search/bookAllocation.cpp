#include <bits/stdc++.h>
using namespace std;

// Book Allocation 

int pagesChecker(vector<int> &arr, int N, int m, int s) {
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

int bookAllocation(vector<int> &arr, int N, int s) {
    int max=0,sum=arr[0];
    for(int i=0; i<N; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        sum+=arr[i];
    }
    while(max<=sum) {
        int mid = (max+sum)/2;
        int k = pagesChecker(arr, N, mid, s);
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
    v.push_back(25);
    v.push_back(46);
    v.push_back(28);
    v.push_back(49);
    v.push_back(24);
    int bookAlloc = bookAllocation(v, 5, 4);
    cout << bookAlloc;
}
