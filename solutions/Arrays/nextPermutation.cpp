#include <bits/stdc++.h>
using namespace std;

// Next Permutation

void nextPermutation(vector <int> &arr) {
    int N = arr.size();
    int breaker = -1;
    for(int i=N-2; i>=0; i--) {
        if(arr[i] < arr[i+1]) {
            breaker = i;
            break;
        }
    }
    if(breaker==-1) {
        reverse(arr.begin(), arr.end());
        return;
    } else {
        for(int i=N-1; i>breaker; i--) {
            if(arr[i] > arr[breaker]) {
                int temp = arr[i];
                arr[i] = arr[breaker];
                arr[breaker] = temp;
                break;
            }
        }
        reverse(arr.begin()+breaker+1, arr.end());
    }
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    nextPermutation(v);
    for(int i = 0; i<7; i++) {
        cout << v[i] << endl;
    }
}