#include <bits/stdc++.h>
using namespace std;

// Maximum Product Subarray

int binarySearchIterative(vector<int> &arr, int N, int a) {
    int low = 0;
    int high = N-1;
    while (low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            return mid;
        } else if (arr[mid] < a) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return -1;
}

int binarySearchRecursive(vector<int> &arr, int low, int high, int a) {
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid] == a) {
        return mid;
    } else if(arr[mid] < a) {
        return binarySearchRecursive(arr, mid+1, high, a);
    } else {
        return binarySearchRecursive(arr, low, mid-1, a);
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int find4 = binarySearchIterative(v, 5, 4);
    int find3 = binarySearchRecursive(v, 0, 4, 3);
    cout << find4 << " " << find3;
}
