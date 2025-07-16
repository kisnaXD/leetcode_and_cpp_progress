#include <bits/stdc++.h>
using namespace std;

// Print all Divisors

vector<int> printAllDivisors(int N) {
    vector<int> v;
    for(int i=1; i<sqrt(N); i++) {
        if(N%i == 0) {
            v.push_back(i);
            if(i != N/i) {
                v.push_back(N/i);
            }
        } else {
            continue;
        }
    }
    return v;
}

int main() {
    int N = 36;
    vector<int> v = printAllDivisors(N);
    for(auto it: v) {
        cout << it << " ";
    }
    return 0;
}