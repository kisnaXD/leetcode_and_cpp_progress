#include <bits/stdc++.h>
using namespace std;

// Generate all subsets of a given array of numbers

vector<vector<int> > subsets(vector<int>& arr) {
    vector<vector<int> > ans;
    int N = arr.size();
    int subsets = 1<<N;
    for(int i=0; i<subsets; i++) {
        vector<int> lists;
        for(int j=0; j<N; j++) {
            if(i & (1<<j)) {
                lists.push_back(arr[j]);
            }
        }
        ans.push_back(lists);
    }
    return ans;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector< vector< int> > answer = subsets(v);
    for(vector<int> v1 : answer) {
        for(int x : v1) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}