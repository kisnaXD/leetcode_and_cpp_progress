#include <bits/stdc++.h>
using namespace std;

// Search Insert position

int searchInsert(vector<int> &arr, int N, int a) {
    int low = 0;
    int ans = N;
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
int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    int find3 = searchInsert(v, 4, 3);
    cout << find3;
}
