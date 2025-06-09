#include <bits/stdc++.h>
using namespace std;

// Peak Element

int peakElement(vector<int>& arr, int N) {
    if(N==1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[N-1] > arr[N-2]) return N-1;
    int low = 1, high = N-2;
    while(low<=high) {
        int mid = (low+high)/2;
        cout << low << " " << mid << " " << high << "\n";
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) {
            return mid;
        } else if (arr[mid] > arr[mid-1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
};

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(3);
    int peak = peakElement(v, 7);
    cout << peak;
}
