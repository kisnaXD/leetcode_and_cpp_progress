#include <bits/stdc++.h>
using namespace std;

// Floor & Ceiling

int floorOfSortedArray(vector<int> &arr, int N, int a) {
    int low = 0;
    int ans = -1;
    int high = N-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            return arr[mid];
        } else if (arr[mid] < a) {
            ans = arr[mid];
            low = mid + 1;
        } else {
            high = mid-1;
        }
    } 
    return ans;
}
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    int find3 = floorOfSortedArray(v, 4, 3);
    cout << find3;
}
