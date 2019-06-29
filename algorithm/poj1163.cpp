#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 101
int d[101][101], n;
int MaxSum[101][101];

int maxSum(int row, int col) {
    if (MaxSum[row][col] != -1) {
        return MaxSum[row][col];
    }
    int max1 = maxSum(row + 1, col);
    int max2 = maxSum(row + 1, col + 1);
    MaxSum[row][col] = d[row][col] + (max1 > max2 ? max1 : max2);
    return MaxSum[row][col];
}

int main() {
    cin >> n;
    memset(MaxSum, -1, sizeof(MaxSum));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            cin >> d[i][j];
            if (i == n-1)
                MaxSum[i][j] = d[i][j];
        }
    }
    int res = maxSum(0, 0);
    cout << res << endl;
    return 0;
}