/*
 * 1) 同一个位置涂两次，则两次的结果抵消，不会产生任何效果，
 *    因此，每个位置最多只涂一次。
 * 2) 各个位置涂抹的顺序对最终的结果没有影响。
 * 3) 第一行的颜色可以通过第二行的操作进行改变，第二行的颜色
 *    可以同过第三行的操作进行改变。
 * 综上所述，只要枚举第一行的状态，后面行的状态就随之确定了。
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXN 17
int N;
int block[MAXN][MAXN];
int ans[MAXN][MAXN];
int result = 1000;

bool check_ans(){
    for (int i = 2; i <= N + 1; ++ i) {
        for (int j = 1; j <= N; ++j) {
            ans[i][j] = block[i - 1][j] ^ ans[i-1][j] 
                    ^ ans[i - 1][j - 1] ^ ans[i - 1][j + 1] ^ ans[i - 2][j];
        }
    }
    for (int j = 1; j <= N; ++ j) {
        if (ans[N + 1][j] == 1) return false;
    }
    return true;
}

void solve(){
    for (int i = 0; i < (1 << N); ++ i) {
        int k = i;
        for (int j = 1; j <= N; ++ j) {
            ans[1][j] = k % 2;
            k /= 2;
        }
        if (check_ans()){
            int temp = 0;
            for (int i = 0; i <= N; ++ i) {
                for (int j = 0; j <= N; ++ j) {
                    if(ans[i][j] == 1) ++temp;
                }
            }
            if (temp < result) result = temp;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(block, 0, sizeof(int)*MAXN*MAXN);
        memset(ans, 0, sizeof(int)*MAXN*MAXN);
        result = 1000;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++ i) {
            //getchar();
            for (int j = 1; j <= N; ++ j) {
                char c;
                cin >> c;
                if (c == 'w') {
                    block[i][j] = 1;
                } else if (c == 'y'){
                    block[i][j] = 0;
                }
            }
        }
        solve();
        if (result == 1000)
           printf("inf\n");
        else
           printf("%d\n", result);

    }
    return 0;
}