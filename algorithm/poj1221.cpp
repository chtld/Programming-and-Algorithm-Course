#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

// 要使用长双精度的整数，否则会由于数字太大溢出
long long num[250][250];

void fun() {
    memset(num, 0, sizeof(num));
    // 注意边界条件， 大于等于某个数的子串数量至少有一个
    for (int i = 0; i < 250; ++ i) {
        for (int j = 0; j < 250; ++ j) {
            if (i == 0) {
                num[i][j] = 1;
            } else if (j > i) {
                num[i][j] = 0;
            } else {
                num[i][j] = 1;
            }
        }
    }
    for (int i = 2; i < 250; ++ i) {
        num[i][i] = 1;
        for (int j = i / 2; j  >= 1; -- j) {
            num[i][j] = num[i - 2 * j][j] + num[i][j + 1];
        }
    }
}


int main(){
    int n;
    fun();
    while (true) {
        cin >> n;
        if (n == 0) break;
        long long ans = 0;
        ans = num[n][1];
        cout << n << ' ' << ans << endl; 
    }
    return 0;
}