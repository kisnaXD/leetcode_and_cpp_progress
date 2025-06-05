#include <bits/stdc++.h>
using namespace std;

// Counting Inversions
int cnt = 0;
void merge(vector <int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int i = low;
    int j = mid+1;
    while(i<=mid && j<=high) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i+=1;
        } else {
            cnt += mid-i+1;
            temp.push_back(arr[j]);
            j+=1;
        }
    }
    while(i<=mid) {
        temp.push_back(arr[i]);
        i+=1;
    }
    while(j<=high) {
        temp.push_back(arr[j]);
        j+=1;
    }
    for(int c = low; c<=high; c++) {
        arr[c] = temp[c-low];
    }
}

void mS(vector<int> &arr, int low, int high) {
    if(low == high) return;
    int mid = (low+high)/2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    mS(v, 0, 4);
    cout << cnt;
}
