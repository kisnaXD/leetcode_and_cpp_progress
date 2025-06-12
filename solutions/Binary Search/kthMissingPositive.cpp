#include <bits/stdc++.h>
using namespace std;

// k'th Missing positive Integer

int kthMissing(vector<int> &arr, int N, int K) {
    int low = 0, high=N-1;
    while(low<=high) {
        int mid = (low+high)/2;
        int missing = arr[mid] - mid - 1;
        if(missing < K) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + K;
}
int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);
    v.push_back(11);
    int kthmissing = kthMissing(v, 5, 5);
    cout << kthmissing;
}
