#include <bits/stdc++.h>
using namespace std;

// Counting Primes Upto N

int countPrimes(int N) {
    vector<int> prime;
    prime.push_back(0);
    prime.push_back(0);
    for(int i=2; i<N; i++) {
        prime.push_back(1);
    }
    for(int i=2; i<sqrt(N); i++) {
        if(prime[i] == 1) {
            for(int j=i*i; j<N; j+=i) {
                prime[j] = 0;
            }
        }
    }
    int c = 0;
    for(int i=2; i<N; i++) {
        if(prime[i] == 1) {
            c++;
        }
    }
    return c;
}

int main() {
    cout << countPrimes(30);
    return 0;
}