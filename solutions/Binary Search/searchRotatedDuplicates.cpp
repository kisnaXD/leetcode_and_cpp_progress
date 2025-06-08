#include <bits/stdc++.h>
using namespace std;

// Search in Rotated Sorted Array (with Duplicates)

int searchRotatedSorted2(vector<int> &arr, int N, int a) {
    int low = 0;
    int high = N-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            return 1;
        } else if(arr[mid] == arr[low] == arr[high]) {
            low ++;
            high --;
        } else if(arr[mid] <= arr[high]) {
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
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    int rotatedthree = searchRotatedSorted2(v, 7, 1);
    cout << rotatedthree;
}
