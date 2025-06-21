#include <bits/stdc++.h>
using namespace std;

// Roman Numerals to Integers

int c2n(char a) {
    switch(a) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string str, int N) {
    int result = 0;
    for(int i=0; i<N; i++) {
        if(i+1 < N && c2n(str[i]) < c2n(str[i+1])) {
            result -= c2n(str[i]);
        } else {
            result += c2n(str[i]);
        }
    }
    return result;
}

int main() {
    string str = "XXV";
    cout << romanToInt(str, str.size());
}
