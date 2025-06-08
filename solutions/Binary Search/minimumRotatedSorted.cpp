#include <bits/stdc++.h>
using namespace std;

// Minimum in Rotated Sorted Array

int minimumInRotatedSorted(vector<int> &arr, int N) {
    int low = 0;
    int high = N-1;
    int ans = INT_MAX;
    while(low<=high) {
        int mid = (low+high)/2;
        ans = ans < arr[mid] ? ans : arr[mid];
        if(arr[mid] <= arr[high]) {
            ans = ans < arr[mid] ? ans : arr[mid];
            high = mid - 1;
        } else {
            ans = ans < arr[low] ? ans : arr[low];
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    int minimum = minimumInRotatedSorted(v, 4);
    cout << minimum;
}
