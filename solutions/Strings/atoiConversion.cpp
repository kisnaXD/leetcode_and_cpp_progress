#include <bits/stdc++.h>
using namespace std;

// Atoi Conversion to Signed Integer

int myAtoi(string str) {
    long long result = 0;
    bool neg = false;
    int N = str.length();
    bool numRead = false;
    for(int i=0; i<N; i++) {
        if(str[i] == ' ' && !numRead) {
            continue;
        }
        if(str[i] == '-' && !numRead) {
            neg = true;
            numRead = true;
            continue;
        }
        if(str[i] == '+' && !numRead) {
            neg = false;
            numRead = true;
            continue;
        }
        if((char)str[i] < '0' || (char)str[i] > '9' || str[i]== ' ') {
            break;
        }
        result = result*10 + (str[i] - '0');
        numRead = true;
    }
    result = neg ? -1 * result : result;
    result = result > INT_MAX ? INT_MAX : result;
    result = result < INT_MIN ? INT_MIN : result;
    return (int) result;
}

int main() {
    string str = "1730cd8";
    cout << myAtoi(str);
}