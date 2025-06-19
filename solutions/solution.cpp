#include <bits/stdc++.h>
using namespace std;

// Largest Odd Number

string largestOdd(string str, int N) {
    for(int i=N-1; i>=0; i--) {
        if((str[i] - '0')%2 != 0) {
            return str.substr(0, i+1);
        }
    }
    return "";
}

int main() {
    string myStr = "30527";
    string largest = largestOdd(myStr, myStr.size());
    cout << largest;
}
