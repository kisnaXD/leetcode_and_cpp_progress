#include <bits/stdc++.h>
using namespace std;

// Find the row with most number of ones in a 2D array

int mostNumberOfOnes(vector<vector<int> > &arr, int M, int N) {
    int maxOnes = 0;
    for(int i=0; i<M; i++) {
        // Just implement function where we find lower bound of 1 because the array will only have 0s or 1s
        int low = 0; 
        int high = arr[i].size();
        int ans = -1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(arr[i][mid] == 1) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        if(ans==-1) {
            ans = 0;
        } else {
            ans = N - ans;
        }
        maxOnes = max(maxOnes, ans);
    }
    return maxOnes;
}

int main() {
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);

    vector<int> v3;
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(1);

    vector<int> v2;
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(1);

    vector<int> v4;
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(1);
    v4.push_back(1);

    vector<int> v5;
    v5.push_back(0);
    v5.push_back(0);
    v5.push_back(0);
    v5.push_back(0);
    v5.push_back(0);

    vector< vector<int> > v6;
    v6.push_back(v1);
    v6.push_back(v2);
    v6.push_back(v3);
    v6.push_back(v4);
    v6.push_back(v5);

    int answer = mostNumberOfOnes(v6, 5, 5);
    cout << answer;
}
