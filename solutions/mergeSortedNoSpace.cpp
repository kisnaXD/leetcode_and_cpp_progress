#include <bits/stdc++.h>
using namespace std;

// Merge Two Sorted Arrays without using any Extra Space

void mergeSortedNoSpace(vector<int> &arr1, int m, vector<int> &arr2, int n) {
    int left = m-1;
    int right = 0;
    while(left >=0 && right <n) {
        if(arr1[left] > arr2[right]) {
            int temp = arr1[left];
            arr1[left] = arr2[right];
            arr2[right] = temp;
        } else {
            break;
        }
        left--;
        right++;
    }
    sort(arr1.begin(), arr1.begin() + m);
    sort(arr2.begin(), arr2.end());
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(6);
    mergeSortedNoSpace(v, 3, v1, 3);
    for(auto it: v) {
        cout << it << " ";
    }
    cout << endl;
    for(auto it: v1) {
        cout << it << " ";
    }
}

