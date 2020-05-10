#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int start[50], End[50];
int a[50][50];

int gauss(int equ, int var) {
    int col = 0;
    int k;
    for (k = 0; k < equ && col < var; k++, col++) {
        int maxRow = k;
        for (int i = k + 1; i < equ; ++ i) {
            if (abs(a[i][col]) > abs(a[maxRow][col]))
                maxRow = i;
        }
        if (maxRow != k) {
            for (int j = k; j < var + 1; ++ j)
                swap(a[k][j], a[maxRow][j]);
        }
        if (a[k][col] == 0) {
            k--;
            continue;
        }
        for (int i = k + 1; i < equ; ++i) {
            if (a[i][col] != 0) {
                for (int j = col; j < var + 1; ++ j) {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (int i = k; i < equ; ++i) {
        if (a[i][col] != 0)
            return -1;
    }
    return var - k;
}



int main(){
    int k, n;
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 0; i < n; ++ i) {
            cin >> start[i];
        }
        for (int i = 0; i < n; ++ i) {
            cin >> End[i];
        }
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; ++ i) {
            a[i][n] = start[i] ^ End[i];
            a[i][i] = 1;
        }
        while (true) {
            int I, J;
            cin >> I >> J;
            if (I == 0 && J == 0) break;
            a[J - 1][I - 1] = 1;
        }
        int freenum = gauss(n, n);
        if (freenum == -1) {
            cout << "Oh,it's impossible~!!" << endl;
        } else {
            cout << (1<<freenum) << endl;
        }
    }
    return 0;
}