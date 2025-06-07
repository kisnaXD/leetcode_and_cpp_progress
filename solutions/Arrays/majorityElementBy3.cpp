#include <bits/stdc++.h>
using namespace std;

// Majority Element - II 

vector<int> majorityElementNBy3(vector<int> &arr, int N) {
    vector<int> v;
    int count1=0, count2=0, el1=INT_MIN, el2=INT_MIN;
    for(int i=0; i<N; i++) {
        if(count1==0 && el2 != arr[i]) {
            count1=1;
            el1 = arr[i];
        } else if (count2==0 && el1 != arr[i]) {
            count2=1;
            el2 = arr[i];
        } else if (arr[i] == el1) {
            count1++;
        } else if(arr[i] == el2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    count1=0, count2=0;
    for(int i=0; i<N; i++) {
        if(el1 == arr[i]) count1++;
        if(el2 == arr[i]) count2++;
    }
    int mini = (int)(N/3 + 1);
    if(count1>=mini) {
        v.push_back(el1);
    }
    if(count2>=mini) {
        v.push_back(el2);
    }
    if(v.size() == 2) {
        if(v[0] > v[1]) {
            int temp = v[0];
            v[0] = v[1];
            v[1] = temp;
        }
    }
    return v;
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(1);
    vector<int> ans = majorityElementNBy3(v, 9);
    for(auto it: ans) {
        cout << it << endl;
    } 
    return 0;
}