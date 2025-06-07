#include <bits/stdc++.h>
using namespace std;

// Quick Sort

int pivotPlace(vector <int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j) {
        while(arr[i] <= pivot && i<=high - 1) {
            i+=1;
        }
        while(arr[j] >= pivot && j>=low + 1) {
            j-=1;
        }
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;
    return j;
}

void qS(vector <int> &arr, int low, int high) {
    if(low < high) {
        int halfing = pivotPlace(arr, low, high);
        qS(arr, low, halfing);
        qS(arr, halfing+1, high);
    } else return;
}

int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    qS(v, 0, 4);
    for(int i=0; i<5; i++) {
        cout << v[i] << endl;
    }
}