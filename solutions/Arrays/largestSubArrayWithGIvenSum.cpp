#include <bits/stdc++.h>
using namespace std;

// Longest Sub Array with given sum (for both positives and negatives and only non-negatives)

int longestSubArrayWithGivenSumPosi(vector <int> &arr, int N, int K) {
    int i=0, j=0, sum=arr[0], len = 0;
    while(j<N) {
        while (j>=i && sum>K) {
            sum-=arr[i];
            i++;
        }
        if(sum == K) {
            len = len>(j-i+1) ? len : j-i+1;
        }
        j++;
        if(j<N) sum+=arr[j];
    }
    return len;
}

int longestSubArrayWithGivenSum(vector <int> &arr, int N, int K) {
    map<long long, int> preSumMap;
    int sum=0;
    int len=0;
    for(int i=0; i<N; i++) {
        sum+=arr[i];
        if(sum == K) {
            len = len>(i+1) ? len : (i+1);
        }
        long long rem = sum - K;
        if(preSumMap.find(rem) != preSumMap.end()) {
            len = len>(i-preSumMap[rem]) ? len : (i-preSumMap[rem]);
        }
        preSumMap[sum] = i;
    }
    return len;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(6);
    int longestSubArrayLen1 = longestSubArrayWithGivenSum(v, 5, 2);
    int longestSubArrayLen2 = longestSubArrayWithGivenSumPosi(v,5,2);
    cout << longestSubArrayLen1<< endl;
    cout << longestSubArrayLen2<< endl;
}