#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int s[9][9];
int sum[9][9];
int res[15][9][9][9][9];

int calSum(int x1, int y1, int x2, int y2) {
    return (sum[x2][y2] - sum[x2][y1 - 1] - sum[x1-1][y2] + sum[x1 - 1][y1 - 1]);
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int fun(int n, int x1, int y1, int x2, int y2) {
    int temp, cut, remain, MIN = 10000000;
    if (res[n][x1][y1][x2][y2] != -1) {
        return res[n][x1][y1][x2][y2];
    }
    if (n == 1) {
        temp = calSum(x1, y1, x2, y2);
        res[n][x1][y1][x2][y2] = temp*temp;
        return res[n][x1][y1][x2][y2];
    }
    for (int i = x1; i < x2; ++ i) {
        cut = calSum(x1, y1, i, y2);
        remain = calSum(i + 1, y1, x2, y2);
        temp = min(cut*cut + fun(n - 1, i + 1, y1, x2, y2),
                    remain*remain + fun(n - 1, x1, y1, i, y2));
        MIN = min(MIN, temp);
    }
    for (int i = y1; i < y2; ++ i) {
        cut = calSum(x1, y1, x2, i);
        remain = calSum(x1, i + 1, x2, y2);
        temp = min(cut*cut + fun(n - 1, x1, i + 1, x2, y2),
                    remain*remain + fun(n - 1, x1, y1, x2, i));
        MIN = min(MIN, temp);
    }
    res[n][x1][y1][x2][y2] = MIN;
    return MIN;
}

int main(){
    int n;
    cin >> n;
    memset(s, 0, sizeof(s));
    memset(sum, 0, sizeof(sum));
    memset(res, -1, sizeof(res));
    for (int i = 1; i < 9; ++ i) {
        for (int j = 1, rowsum = 0; j < 9; ++ j) {
            cin >> s[i][j];
            rowsum += s[i][j];
            sum[i][j] = sum[i - 1][j] + rowsum;
        }
    }
    double result = n*fun(n, 1, 1, 8, 8) - sum[8][8]*sum[8][8];
    //cout << setiosflags(ios::fixed) << setprecision(3) << sqrt(result/(n*n)) << endl;
    printf("%.3lf", sqrt(result/(n*n)));
    return 0;
}