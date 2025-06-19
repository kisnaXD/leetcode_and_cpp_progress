#include <bits/stdc++.h>
using namespace std;

// Reverse Words in a String

string reverseWords(string str, int N) {
    int i=0, right=0, left=0;
    reverse(str.begin(), str.end());
    while(i<N) {
        while(i<N && str[i] == ' ') {
            i++;
        }
        if(i==N) {
            break;
        }
        while(i<N && str[i] != ' ') {
            str[right] = str[i];
            right++;
            i++;
        }
        reverse(str.begin() + left, str.begin() + right);
        str[right] = ' ';
        right++;
        left = right;
        i ++;
    }
    str.resize(right-1);
    return str;
}

int main() {
    string myStr = "Hello World    Hi";
    string answer = reverseWords(myStr, myStr.size());
    cout << answer;
}
