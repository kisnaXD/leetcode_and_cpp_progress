#include <bits/stdc++.h>
using namespace std;

// Median in a row wise sorted 2d matrix

int findLowest(vector< vector<int> > &arr, int M, int N) {
    int low = INT_MAX;
    for(int i=0; i<M; i++) {
        if(arr[i][0] < low) {
            low = arr[i][0];
        }
    }
    return low;
}

int findHighest(vector< vector<int> > &arr, int M, int N) {
    int high = INT_MAX;
    for(int i=0; i<M; i++) {
        if(arr[i][N-1] > high) {
            high = arr[i][0];
        }
    }
    return high;
}

int blackBox(vector< vector<int> >&arr, int M, int N, int K) {
    int ans = 0;
    for(int i=0; i<M; i++) {
        int low = 0;
        int high = N-1;
        int ub = 0;
        while(low<=high) {
            int mid = (low+high)/2;
            if(arr[i][mid] <= K) {
                ub = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans+=ub;
    }
    return ans;
}

int median2DRowwise(vector< vector<int> >&arr, int M, int N) {
    int low = findLowest(arr, M, N);
    int high = findHighest(arr, M, N);
    while(low<=high) {
        int mid = (low+high)/2;
        int smallerEquals = blackBox(arr, M, N, mid);
        if(smallerEquals <= M*N/2) {
            low = mid +1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(7);
    v1.push_back(11);
    v1.push_back(15);

    vector<int> v3;
    v3.push_back(2);
    v3.push_back(5);
    v3.push_back(8);
    v3.push_back(12);
    v3.push_back(19);

    vector<int> v2;
    v2.push_back(3);
    v2.push_back(6);
    v2.push_back(9);
    v2.push_back(16);
    v2.push_back(22);

    vector<int> v4;
    v4.push_back(10);
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(17);
    v4.push_back(24);

    vector<int> v5;
    v5.push_back(18);
    v5.push_back(21);
    v5.push_back(23);
    v5.push_back(26);
    v5.push_back(30);

    vector< vector<int> > v6;
    v6.push_back(v1);
    v6.push_back(v2);
    v6.push_back(v3);
    v6.push_back(v4);
    v6.push_back(v5);

    int answer = median2DRowwise(v6, 5, 5);
    cout << answer;
}
