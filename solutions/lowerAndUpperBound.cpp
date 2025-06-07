#include <bits/stdc++.h>
using namespace std;

// Lower Bound & Upper Bound

int lowerBound(vector<int> &arr, int N, int a) {
    int low = 0;
    int ans = N-1;
    int high = N-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            while(arr[mid] == arr[mid-1]) {
                mid --;
            }
            return mid;
        } else if (arr[mid] < a) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid-1;
        }
    } 
    return ans;
}

int upperBound(vector<int> &arr, int N, int a) {
    int low = 0;
    int ans = 0;
    int high = N-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            while(arr[mid] == arr[mid+1]) {
                mid ++;
            } 
            return mid;
        } else if (arr[mid] < a) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int lb = lowerBound(v, 5, 1);
    int ub = upperBound(v, 5, 1);
    cout << lb << " " << ub;
}
