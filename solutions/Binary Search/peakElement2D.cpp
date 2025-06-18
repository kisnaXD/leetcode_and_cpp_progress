#include <bits/stdc++.h>
using namespace std;

// Finding peak Element in 2D Matrix

int findMaxIndex(vector< vector<int> >&arr, int M, int N, int col) {
    int maxValue = -1;
    int index = -1;
    for(int i=0; i<M; i++) {
        if(arr[i][col] > maxValue) {
            maxValue = arr[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> peakIndex(vector< vector< int > > &arr, int M, int N) {
    int low = 0, high = N-1;
    while(low<=high) {
        int mid = (low+high)/2;
        int maxIndex = findMaxIndex(arr, M, N, mid);
        int left = mid - 1 >=0 ? arr[maxIndex][mid - 1] : -1;
        int right = mid + 1 < N ? arr[maxIndex][mid+1] : -1;
        if(arr[maxIndex][mid] > left && arr[maxIndex][mid] > right) {
            vector<int> v;
            v.push_back(maxIndex);
            v.push_back(mid);
            return v;
        } else if (arr[maxIndex][mid] < left) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
    return v;
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

    vector<int> answer = peakIndex(v6, 5, 5);
    for(auto it: answer) {
        cout << it << " ";
    }
}
