#include<iostream>

using namespace std;


int func(int n, int m) {
    if (n == 1 || m == 1) {
        return 1;
    } else if (n < 1 || m < 1) {
        return 0;
    } else if (n < m) {
        return func(n, n);
    } else if (n == m) {
        return func(n, n - 1) + 1;
    } else {
        return func(n - m, m) + func(n, m - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        cout << func(n, n) << endl;
    }
    return 0;
}