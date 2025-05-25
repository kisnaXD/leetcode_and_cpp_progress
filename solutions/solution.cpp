#include <bits/stdc++.h>
using namespace std;

// Shift an array to the left by K places

void shiftLeftByOne(vector <int> &arr, int N) {
    int temp = arr[0];
    for(int i=1; i<N; i++) {
        arr[i-1] = arr[i];
    }
    arr[N-1] = temp;
}

void reverse(vector <int> &arr, int low, int high) {
    int stop = (high+low)/2;
    for(int i=low; i<=stop; i++) {
        int temp = arr[i];
        arr[i] = arr[high+low-i];
        arr[high+low-i] = temp;
    }
}

void shiftLeftByK(vector <int> &arr, int N, int K) {
    K = K%N;
    reverse(arr, 0, K-1);
    reverse(arr, K, N-1);
    reverse(arr, 0, N-1);
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    shiftLeftByK(v, 5, 3);
    cout << "Output" << endl;
    for(auto it: v) {
        cout << it << endl;
    }
}