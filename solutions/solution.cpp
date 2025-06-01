#include <bits/stdc++.h>
using namespace std;

// 4 Sum Problem

vector< vector < int > > fourSumProblem(vector<int> arr, int N, int K) {
    vector< vector< int > > st;
    for(int i=0; i<N-3; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j=i+1; j<N-2; j++) {
            if(j!=i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1, l=N-1;
            
            while(k<l) {
                int sum = arr[i] + arr[j]+arr[k]+arr[l];
                if(sum>K) {
                    l--;
                } else if(sum<K) {
                    k++;
                } else {
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(arr[k]);
                    v.push_back(arr[l]);
                    st.push_back(v);
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
            }
        }
    }
    return st;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(4);
    v.push_back(5);
    v.push_back(5);
    vector< vector< int > > ans = fourSumProblem(v, 14, 8);
    for(auto it: ans) {
        for(auto itt: it) {
            cout << itt << " ";
        }
        cout << endl;
    } 
    return 0;
}