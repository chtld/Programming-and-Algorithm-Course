#include<iostream>

using namespace std;

int func (int N) {
    int dp0 = 1, base = 1, dp1;
    for (int i = 2; i <= N; ++ i) {
        dp1 = (dp0 * N + 1) / (N - 1);
        if (dp1 * (N - 1) != dp0 * N + 1) {
            i = 1;
            base++;
            dp0 = base;
            continue;
        }
        dp0 = dp1;
        //cout << dp1 << endl;
    }
    return dp1 * N + 1;
}



int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        cout << func(N) << endl;
    }
    return 0;
}