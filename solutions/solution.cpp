#include <bits/stdc++.h>
#include <stack>
using namespace std;

// Queue Implementation Using Stack (Enqueue becomes O(2N))

class queueUsingStack {
    stack<int> s1, s2;
    public:
        void enqueue(int x) {
            while(s1.size() > 0) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(s2.size() > 0) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        void dequeue() {
            s1.pop();
        }

        int top() {
            return s1.top();
        }

        int size() {
            return s1.size();
        }
};

int main() {
    int n = 8;

    return 0;
}