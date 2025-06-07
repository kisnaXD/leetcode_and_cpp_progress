#include <bits/stdc++.h>
using namespace std;

// Find Missing and Repeating Numbers

pair<int,int> missingAndRepeating(vector<int> &arr, int N) {
    int sum1 = N * (N+1) / 2;
    int sum2 = N * (N+1) * (2*N+1) / 6;
    int s1 = 0, s2 = 0;
    for(int i = 0; i<N; i++) {
        s1+=arr[i];
        s2+=arr[i]*arr[i];
    }
    int xMinusY = s1 - sum1;
    int x2MinusY2 = s2 - sum2;
    int xPlusY = x2MinusY2 / xMinusY;
    int x = (xMinusY + xPlusY) / 2;
    int y = (xPlusY - xMinusY) / 2;
    pair <int, int> p;
    p.first = x;
    p.second = y;
    return p;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);
    v.push_back(6);
    pair<int, int> p = missingAndRepeating(v, 6);
    cout << p.first << " " << p.second;
}

