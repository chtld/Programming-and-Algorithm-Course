#include<iostream>
#include<cstring>
using namespace std;

int a[21];

int faboni(int n) {
    if (a[n] != 0)
        return a[n];
    a[n] = faboni(n - 1) + faboni(n - 2);
    return a[n];
}

int main(){
    int n, x;
    memset(a, 0, sizeof(a));
    a[1] = 1;
    a[2] = 1;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> x;
        int ans = faboni(x);
        cout << ans << endl;
    }

    return 0;
}