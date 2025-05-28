#include <bits/stdc++.h>
using namespace std;

// Next Permutation

int pivotPlace(vector <int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j) {
        while(arr[i] <= pivot && i<=high - 1) {
            i+=1;
        }
        while(arr[j] >= pivot && j>=low + 1) {
            j-=1;
        }
        if(i<j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t = arr[low];
    arr[low] = arr[j];
    arr[j] = t;
    return j;
}

void qS(vector <int> &arr, int low, int high) {
    if(low < high) {
        int halfing = pivotPlace(arr, low, high);
        qS(arr, low, halfing);
        qS(arr, halfing+1, high);
    } else return;
}

void nextPermutation(vector <int> &arr, int N) {
    int breaker = 0;
    for(int i=0; i<N; i++) {
        if(arr[i] < arr[i+1]) {
            breaker = i;
            break;
        }
    }
    if(breaker==0) {
        qS(arr, 0, N-1);
    } else {
        int a = arr[breaker];
        int largest = breaker+1;
        for(int i=breaker+1; i<N; i++) {
            if(arr[i] > a && arr[i] < arr[largest]) {
                largest = i;
            }
        }
        int temp = arr[largest];
        arr[largest] = arr[breaker];
        arr[breaker] = temp;
        qS(arr, breaker+1, N-1);
    }
}

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(0);
    v.push_back(0);
    nextPermutation(v, 7);
    for(int i = 0; i<7; i++) {
        cout << v[i] << endl;
    }
}