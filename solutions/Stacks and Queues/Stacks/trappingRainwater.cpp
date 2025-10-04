#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Trapping Rainwater

int trap(vector<int>& arr) {
    int N = arr.size();
    int l=0, r=N-1, rMax=0, lMax=0, total=0;
    while(l<r) {
        if(arr[l] <= arr[r]) {
            if(lMax > arr[l]) {
                total += lMax - arr[l];
            } else {
                lMax = arr[l];
            }
            l+=1;
        } else {
            if(rMax > arr[r]) {
                total += rMax - arr[r];
            } else {
                rMax = arr[r];
            }
            r-=1;
        }
    }
    return total;
}


int main() {
    return 0;
}