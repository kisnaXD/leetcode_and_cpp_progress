#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array (without Duplicates)

int searchRotatedSorted1(vector<int> &arr, int N, int a) {
    int low = 0;
    int high = N-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            return mid;
        } else if(arr[mid] < arr[high]) {
            if(a<=arr[high] && a>=arr[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } else {
            if(a<=arr[mid] && a>=arr[low]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    int rotatedthree = searchRotatedSorted1(v, 4, 3);
    cout << rotatedthree;
}
