#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 101
int d[101][101], n;
int MaxSum[101];

int main() {
    cin >> n;
    memset(MaxSum, -1, sizeof(MaxSum));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            cin >> d[i][j];
            if (i == n-1)
                MaxSum[j] = d[i][j];
        }
    }
    for (int i = n - 2; i >= 0; -- i) {
        for (int j = 0; j <= i; ++ j){
            MaxSum[j] = d[i][j] + (MaxSum[j] > MaxSum[j+1] ? MaxSum[j] : MaxSum[j+1]);
        }
    }
    cout << MaxSum[0] << endl;
    return 0;
}