#include <bits/stdc++.h>
using namespace std;

// Pascal's Triangle

void printNthRow(int N) {
    int ans = 1;
    cout << ans << " ";
    for(int i=1; i<N; i++) {
        ans = ans * (N-i);
        ans = ans / i;
        cout << ans << " ";
    }
}

void pascalsTriangle(int N) {
    for(int i=1; i<=N; i++) {
        printNthRow(i);
        cout << endl;
    }
}

int main() {
    pascalsTriangle(5);
    return 0;
}