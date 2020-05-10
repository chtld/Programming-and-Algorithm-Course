// #include<iostream>
// #include<cstring>
// using namespace std;
// 
// // 使用一个二维数组，上移代表出栈，右移代表入栈，则当出栈次数和入栈次数为n时，问题得到求解
// // 基本情况：一直入栈，从不出栈，res[0][j] = 1;
// 
// int res[16][16] = {0};
// int count;
// int n;
// int main() {
//     cin >> n;
//     memset(res, 0, sizeof(res));
//     for (int j = 1; j <= n; ++ j) {
//         res[0][j] = 1;
//     }
//     for (int j = 1; j <= n; ++ j) {
//         for (int i = 1; i <= j; ++ i) {
//             res[i][j] = res[i][j - 1] + res[i - 1][j];
//         }
//     }
//     count = res[n][n];
//     cout << count << endl;
//     return 0;
// }
#include<cstdio>
using namespace std;

int main()
{
    int n, a = 1;
    scanf("%d", &n);
    for(int i=2; i<=n; i++)
      a = (4 * i - 2) * a / (i + 1);
    printf("%d\n", a);
    return 0;
}