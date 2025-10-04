#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Minimum Stack

class MinStack {
    long long minEle;
    stack<long long> s;
    public:
        MinStack() {
            minEle = INT_MAX;
        }
        
        void push(int val) {
            if(s.empty()) {
                s.push(val);
                minEle = val;
            } else if(val < minEle) {
                s.push(2LL*val - minEle);
                minEle = val;
            } else {
                s.push(val);
            }
        }
        
        void pop() {
            if(s.top() < minEle) {
                minEle = 2*minEle - s.top();
                s.pop();
            } else {
                s.pop();
            }
        }
        
        int top() {
            if(s.top() < minEle) {
                return minEle;
            } else {
                return s.top();
            }
        }
        
        int getMin() {
            return minEle;
        }
};

int main() {
    return 0;
}