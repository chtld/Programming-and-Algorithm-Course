#include<iostream>
#include<cstring>
using namespace std;

int dp[30];

int fun(int n) {
    int sum = 0;
    if (n % 2 == 1)
        return 0;
    if (dp[n] != 0)
        return dp[n];
    for (int i = n; i >= 2; i = i - 2) {
        sum += 2*fun(i - 2);
    }
    sum += fun(n - 2);
    return sum;
}


int main(){
    int n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        int ans = fun(n);
        cout << ans << endl;
    }
    return 0;
}