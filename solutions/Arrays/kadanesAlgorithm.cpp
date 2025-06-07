#include <bits/stdc++.h>
using namespace std;

// Maximum Sub Array sum using Kadane's Algorithm

int maxSubArraySum(vector <int> &arr, int N) {
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i=0; i<N; i++) {
        sum+=arr[i];
        if(sum<0) sum=0;
        maxSum = maxSum < sum ? sum : maxSum;
    }
    return maxSum;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(-4);
    v.push_back(-2);
    v.push_back(1);
    v.push_back(7);
    int kadanesAnswer = maxSubArraySum(v, 5);
    cout << kadanesAnswer;
}