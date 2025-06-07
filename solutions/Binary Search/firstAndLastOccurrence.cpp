#include <bits/stdc++.h>
using namespace std;

// First & Last Occurrences

int firstOccurrence(vector<int> &arr, int N, int a) {
    int low = 0, high = N-1, ans = -1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(arr[mid] == a) {
            ans = mid;
            high = mid - 1;
        } else if(arr[mid] < a){
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}


int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int firstOccurence3 = firstOccurrence(v, 7, 3);
    cout << firstOccurence3;
}
