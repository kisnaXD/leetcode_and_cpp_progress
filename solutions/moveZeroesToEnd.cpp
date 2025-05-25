#include <bits/stdc++.h>
using namespace std;

// Move zeroes to end

void moveZeroesToEnd(vector <int> &arr, int N) {
    int j = -1;
    for(int i=0; i<N; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        } else j = N;
    }
    if(j==N) return;
    int i = j+1;
    while(i < N && j < N) {
        if(arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        } else i++;
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(0);
    v.push_back(0);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    moveZeroesToEnd(v, 10);
    cout << "Output" << endl;
    for(auto it: v) {
        cout << it << endl;
    }
}