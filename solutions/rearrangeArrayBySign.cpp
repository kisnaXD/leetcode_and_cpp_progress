#include <bits/stdc++.h>
using namespace std;

// Rearrange Array by Sign

int* rearrangeArrayBySign(vector <int> &arr, int N) {
    int posi=0;
    int neg=1;
    int* answer = new int[N];
    for(int i=0; i<N; i++) {
        if(arr[i] >= 0) {
            answer[posi] = arr[i];
            posi+=2;
        } else {
            answer[neg] = arr[i];
            neg+=2;
        }
    }
    return answer;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(-4);
    v.push_back(-2);
    v.push_back(1);
    v.push_back(7);
    v.push_back(-10);
    int* answerArray = rearrangeArrayBySign(v, 6);
    for(int i = 0; i<6; i++) {
        cout << answerArray[i] << endl;
    }
}