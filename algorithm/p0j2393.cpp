#include<iostream>

using namespace std;

int N, S, C, Y;

int min (int a, int b) {
    return (a < b) ? a : b;
}

int main(){
    long long ans = 0;
    int p = 0x3f3f3f3f;
    cin >> N >> S;
    for (int i = 0; i < N; ++ i) {
        cin >> C >> Y;
        p = min(p + S, C);
        ans += p * Y;
    }
    cout << ans << endl;
    return 0;
}