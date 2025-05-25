#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy or Sell Stock

int stockBuySell(vector <int> &arr, int N) {
    int mini = arr[0];
    int maxProfit = 0;
    for(int i=0; i<N; i++) {
        int cost = arr[i] - mini;
        maxProfit = maxProfit>cost ? maxProfit : cost;
        mini = mini>arr[i] ? arr[i] : mini;
    }
    return maxProfit;
}

int main() {
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);
    v.push_back(5);
    int profitMaximum = stockBuySell(v, 5);
    cout << profitMaximum << endl;
}