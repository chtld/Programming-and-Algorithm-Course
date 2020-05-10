#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int func(int N) {
    int res = INT_MAX;
    //cerr << res << endl;
    for (int i = 1; i <= N / 3 + 1; ++ i) {
        for (int j = 1; j <= N; ++ j) {
            if (N % (i * j) == 0) {
                int k = N / (i * j);
                res = min(res, 2 * i * j + 2 * i * k + 2 * j * k);
            }
        }
    }
    return res;
}


int main() {
    int C, N;
    cin >> C;
    while (C--) {
        cin >> N;
        //cerr << C << endl;
        cout << func(N) << endl;
    }
    return 0;
}