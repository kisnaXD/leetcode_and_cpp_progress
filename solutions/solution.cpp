#include <bits/stdc++.h>
using namespace std;

// Removing Duplicates from a Sorted Array

int rmDuplicates(vector <int> &arr, int N) {
    int i = 0;
    for(int j=1; j<N; j++) {
        if(arr[j] != arr[i]) {
            arr[i+1] = arr[j];
            i+=1;
        }
    }
    return i+1;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << "Array before removing duplicates" << endl;
    for(auto it: v) {
        cout << it << endl;
    }
    cout << "Number of duplicates : " << rmDuplicates(v, 5) << endl;
    cout << "Array after removing duplicates" << endl;
    for(auto it: v) {
        cout << it << endl;
    }
}