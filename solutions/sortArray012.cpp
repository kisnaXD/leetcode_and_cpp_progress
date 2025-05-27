#include <bits/stdc++.h>
using namespace std;

// Sort an array containing only 0's 1's and 2's

void sortArray012(vector <int> &arr, int N) {
    int low=0, mid=0, high=N-1;
    while(low<=mid && mid<=high) {
        if(arr[mid] == 0) {
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            mid++;
            low++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    sortArray012(v, 5);
    for(auto it : v) {
        cout << it << endl;
    }
}