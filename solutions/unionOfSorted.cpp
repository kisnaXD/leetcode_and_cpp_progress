#include <bits/stdc++.h>
using namespace std;

// Union of Two Sorted Arrays

vector<int> unionOfTwoSortedArrays(vector <int> &arr1, int n1, vector <int> &arr2, int n2) {
    vector <int> final;
    int i=0, j=0;
    while(i<n1 && j<n2) {
        if(arr1[i] <= arr2[j]) {
            if(final.size() == 0 || final.back() != arr1[i]) {
                final.push_back(arr1[i]);
            }
            i+=1;
        } else {
            if(final.size() == 0 || final.back() != arr2[j]) {
                final.push_back(arr2[j]);
            }
            j+=1;
        }
    }
    while(i<n1) {
        if(final.size() == 0 || final.back() != arr1[i]) {
            final.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2) {
        if(final.size() == 0 || final.back() != arr2[j]) {
            final.push_back(arr2[j]);
        }
        j++;
    }
    return final;
}

int main() {
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(5);
    vector<int> output = unionOfTwoSortedArrays(v, 5, v1, 5);
    cout << "Output" << endl;
    for(auto it: output) {
        cout << it << endl;
    }
}