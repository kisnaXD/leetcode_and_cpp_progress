#include <bits/stdc++.h>
using namespace std;

// Two Sum Problem (with and without usage of Map)

pair<int ,int> twoSumProblemWithMap(vector<int> &arr, int N, int K) {
    map<int, int> mpp;
    for(int i=0; i<N; i++) {
        int a = arr[i];
        int r = K - a;
        if(mpp.find(r) != mpp.end()) {
            return make_pair(mpp[r], i);
        }
        mpp[a] = i;
    }
}

pair<int, int> twoSumProblem(vector <int> &arr, int N, int K) {
    // Here we assume that the array is sorted
    int i=0, j=N-1;
    while(j>i) {
        int sum = arr[i] + arr[j];
        if(sum == K) {
            return make_pair(i, j);
        } else if(sum > K) {
            j--;
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    pair<int, int> withMap = twoSumProblemWithMap(v, 5, 8);
    pair<int, int> withoutMap = twoSumProblem(v,5,8);
    cout << withMap.first << endl << withMap.second << endl;
    cout << withoutMap.first << endl << withoutMap.second << endl;
}