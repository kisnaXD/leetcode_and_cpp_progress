#include <bits/stdc++.h>
using namespace std;

// Moore's Voting Algorithm

int majorityElement(vector <int> &arr, int N) {
    int c=0;
    int el;
    for(int i=0; i<N; i++) {
        if(c==0) {
            c=1;
            el = arr[i];
        } else if(arr[i] == el) {
            c+=1;
        } else if(arr[i] != el) {
            c-=1;
        }
    }
    if(c==0) {
        return -1;
    } else {
        c=0;
        for(int i=0; i<N; i++) {
            if(arr[i] == el) {
                c+=1;
            }
        }
        if(c>N/2) {
            return el;
        } else {
            return -1;
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(2);
    v.push_back(7);
    v.push_back(5);
    int majorityEl = majorityElement(v, 5);
    cout << majorityEl << endl;
}