#include <bits/stdc++.h>
using namespace std;

// Rotate Matrix by 90 Degrees

void rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i = 0; i<N; i++) {
        for(int j=0; j<N/2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][N-1-j];
            matrix[i][N-1-j] = temp;
        }
    }
}