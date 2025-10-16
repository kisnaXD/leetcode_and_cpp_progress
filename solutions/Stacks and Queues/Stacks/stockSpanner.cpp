#include <bits/stdc++.h>
#include <stack>
#include <algorithm>
using namespace std;

// Stock Spanner

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {

    }
    int next(int x) {
        int span = 1;
        while(!st.empty() && x >= st.top().first) {
            span+=st.top().second;
            st.pop();
        }
        st.push({x, span});
        return span;
    }
};

int main() {
    return 0;
}