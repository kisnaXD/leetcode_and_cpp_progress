#include <bits/stdc++.h>
using namespace std;

// Element search in fully sorted 2D Array

pair<int, int> eleSearch(vector< vector<int> >&arr, int M, int N, int K) {
    int total = N*M-1;
    pair<int, int> ele;
    ele.first = -1;
    ele.second = -1;
    int low = 0;
    while(low<=total) {
        int mid = (low+total)/2;
        int i = mid/M;
        int j = mid%N;
        if(arr[i][j] == K) {
            ele.first = i;
            ele.second = j;
            return ele;
        } else if(arr[i][j] < K) {
            low = mid + 1;
        } else {
            total = mid - 1;
        }
    }
    return ele;
}

int main() {
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(7);

    vector<int> v3;
    v3.push_back(17);
    v3.push_back(19);
    v3.push_back(20);
    v3.push_back(21);
    v3.push_back(23);

    vector<int> v2;
    v2.push_back(8);
    v2.push_back(11);
    v2.push_back(13);
    v2.push_back(14);
    v2.push_back(15);

    vector<int> v4;
    v4.push_back(24);
    v4.push_back(26);
    v4.push_back(28);
    v4.push_back(29);
    v4.push_back(31);

    vector<int> v5;
    v5.push_back(33);
    v5.push_back(35);
    v5.push_back(36);
    v5.push_back(37);
    v5.push_back(40);

    vector< vector<int> > v6;
    v6.push_back(v1);
    v6.push_back(v2);
    v6.push_back(v3);
    v6.push_back(v4);
    v6.push_back(v5);

    pair<int, int> answer = eleSearch(v6, 5, 5, 23);
    cout << answer.first << " " << answer.second;
}
