

#include <bits/stdc++.h>
using namespace std;

// 3 Sum Problem

vector< vector < int > > threeSumProblem(vector<int> arr, int N, int K) {
    vector< vector< int > > st;
    for(int i=0; i<N; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1, k=N-1;
        
        while(j<k) {
            int sum = arr[i] + arr[j]+arr[k];
            if(sum>K) {
                k--;
            } else if(sum<K) {
                j++;
            } else {
                vector<int> v;
                v.push_back(arr[i]);
                v.push_back(arr[j]);
                v.push_back(arr[k]);
                st.push_back(v);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return st;
}

int main() {
    vector<int> v;
    v.push_back(-2);
    v.push_back(-2);
    v.push_back(-2);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    vector< vector< int > > ans = threeSumProblem(v, 12, 0);
    for(auto it: ans) {
        for(auto itt: it) {
            cout << itt << " ";
        }
        cout << endl;
    } 
    return 0;
}