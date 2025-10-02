#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Stack Implementation using Queue (push becomes O(N))

class stackUsingQueue {
    queue<int> q;
    public:
        void push(int x) {
            int s = q.size();
            q.push(x);
            for(int i=0; i<s; i++) {
                q.push(q.front());
                q.pop();
            }
        }

        void pop() {
            q.pop();
        }

        int top() {
            return q.front();
        }

        int size() {
            return q.size();
        }
};

int main() {
    int n = 8;

    return 0;
}