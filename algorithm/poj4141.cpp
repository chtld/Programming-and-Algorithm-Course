#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int a[7] = {0};
    int w[7] = {0, 1, 2, 3, 5, 10, 20};
    bool dp[1001];
    int sum = 0;
    int count = 0;
    for (int i = 1; i < 7; ++ i) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= 6; ++i) {
        sum += a[i] * w[i];
        for (int j = 1; j <= a[i]; ++ j){
            for (int k = sum; k >= 0; -- k) {
                if (dp[k - w[i]])
                    dp[k] = true;
            }
        }
    }
    for (int i = 1; i <= sum; ++ i) {
        if(dp[i])
            count++;
    }
    cout << "Total=" << count;
    return 0;
}