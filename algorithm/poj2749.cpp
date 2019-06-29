#include<iostream>

using namespace std;

int sol(int n, int d) {
    int sum = 1;
    for (int i = d; i * i <= n; ++ i) {
        if (n % i == 0)
            sum += sol(n/i, i);
    }
    return sum;
}

int main(){
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << sol(x, 2) << endl;
    }
    return 0;
}