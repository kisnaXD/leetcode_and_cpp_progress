#include <bits/stdc++.h>
using namespace std;

// Merge Overlapping Intervals

vector<vector<int>> merge(vector<vector<int>>& arr) {
    int N = arr.size();
    vector< vector <int> > ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<N; i++) {
        if(ans.empty() || ans.back()[1] < arr[i][0]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = ans.back()[1] > arr[i][1] ? ans.back()[1] : arr[i][1];
        }
    }
    return ans;
}