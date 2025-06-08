#include <bits/stdc++.h>
using namespace std;

// How many times has array been rotated

int arrayRotatedCount(vector<int> &arr, int N) {
    int low = 0;
    int high = N-1;
    int ans = 0;
    while(low<=high) {
        int mid = (low+high)/2;
        ans = arr[ans] < arr[mid] ? ans : mid;
        if(arr[mid] <= arr[high]) {
            ans = arr[ans] < arr[mid] ? ans : mid;
            high = mid - 1;
        } else {
            ans = arr[ans] < arr[low] ? ans : low;
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
    int minimum = arrayRotatedCount(v, 4);
    cout << minimum;
}
