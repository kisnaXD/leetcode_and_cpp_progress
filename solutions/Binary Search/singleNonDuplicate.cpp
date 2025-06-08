#include <bits/stdc++.h>
using namespace std;

// Single element in an array of doubles

int singleNonDuplicate(vector<int>& arr, int N) {
    if(N == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[N-1] != arr[N-2]) return arr[N-1];
    int low = 1;
    int high = N-2;
    int ans = 0;
    while(low<=high) {
        int mid = (low+high)/2;
        if(mid==0 && arr[mid] != arr[mid+1]) return arr[mid];
        if(mid==N-1 && arr[mid] != arr[mid-1]) return arr[mid];
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) {
            ans = arr[mid];
            return ans;
        }
        if((mid%2 != 0 && arr[mid-1] == arr[mid]) || (mid%2 == 0 && arr[mid+1] == arr[mid])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    int singleNon = singleNonDuplicate(v, 7);
    cout << singleNon;
}
