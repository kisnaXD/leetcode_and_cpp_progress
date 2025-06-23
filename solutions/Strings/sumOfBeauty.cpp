#include <bits/stdc++.h>
using namespace std;

// Sum of Beauties of all Substrings

int beautySum(string str, int N) {
    int ans = 0;
    for(int i=0; i<N; i++) {
        int freq[26] = {};
        for(int j=i; j<N; j++) {
            char ch = str[j];
            freq[ch-'a']+=1;
            int min_ans = INT_MAX;
            int max_ans = INT_MIN;
            for(int k=0; k<26; k++) {
                if(freq[k]>0) {
                    min_ans = min(min_ans, freq[k]);
                    max_ans = max(max_ans, freq[k]);
                }
            }
            ans+=max_ans-min_ans;
        }
    }
    return ans;
}

int main() {
    string str = "aabcdeaa";
    int ans = beautySum(str, 8);
    cout << ans;
}