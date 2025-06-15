#include <bits/stdc++.h>
using namespace std;

// Element search in fully sorted 2D Array

pair<int, int> eleSearchRowColumnWise(vector< vector<int> >&arr, int M, int N, int K) {
    int i = 0;
    pair<int, int> ele;
    ele.first = -1;
    ele.second = -1;
    int j = N-1;
    while(i<M && j>=0) {
        if(arr[i][j] == K) {
            ele.first = i;
            ele.second = j;
            return ele;
        } else if (arr[i][j] > K) {
            j--;
        } else {
            i++;
        }
    }
    return ele;
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

    pair<int, int> answer = eleSearchRowColumnWise(v6, 5, 5, 23);
    cout << answer.first << " " << answer.second;
}
