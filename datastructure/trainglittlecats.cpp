#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct matrix{
    long long a[120][120];
    int n;
    matrix(int _n){
        n = _n;
        memset(a, 0, sizeof(a));
    }
    matrix operator*(matrix b){
        matrix res(n);
        for (int i = 1; i <= n; ++ i) {
            for (int k = 1; k <= n; ++ k) {
                if (a[i][k]) {
                    for (int j = 1; j <= n; ++ j) {
                        res.a[i][j] += a[i][k] * b.a[k][j];
                    }
                }
            }
        }
        return res;
    }
    void ones() {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; ++ i) {
            a[i][i] = 1;
        }
    }
    void get(int i) {
        a[i][n] ++;
    }
    void eat(int i) {
        for (int j = 1; j <= n; ++ j){
            a[i][j] = 0;
        }
    }
    void sswap(int i, int j) {
        for (int k = 1; k <= n; ++ k) {
            swap(a[i][k], a[j][k]);
        }
    }
};
matrix quick_power(matrix a, long long m){
        matrix res(a.n);
        res.ones();
        while (m) {
            if (m & 1) res = res * a;
            m >>= 1;
            a = a * a;
        }
        return res;
}

int main(){
    int n, m, k;
    while (true) {
    cin >> n >> m >> k;
    if (n == 0 && m == 0 && k == 0) break;
    matrix a(n + 1);
    a.ones();
    int r1, r2;
    //cerr << "here1" << endl;
    for (int i = 0; i < k; ++ i) {
        char c;
        cin >> c;
        //cerr << "here2" << endl;
        switch (c)
        {
        case 'g':
            cin >> r1;
            a.get(r1);
            break;
        case 'e':
            cin >> r1;
            a.eat(r1);
            break;
        case 's':
            cin >> r1 >> r2;
            a.sswap(r1, r2);
            break;
        }
    }
    //cerr << "here3" << endl;
    a = quick_power(a, m);
    for (int i = 1; i <= n; ++ i) {
        cout << a.a[i][n+1] << " ";
    }
    cout << endl;
    }
    return 0;
}