#include<iostream>
#include<cmath>
using namespace std;

int ans;

void count(double a[], int n){
    double b[4];
    if (n == 1 && a[0] > 0 && abs(a[0] - 24) < 0.0001)
        ans = 1;
    else if (n > 1) {
        for (int i = 0; i < n; ++ i) {
            for(int j = 0; j < n; ++ j) {
                if (i == j)
                    continue;
                int m = 0, k = 0;
                for (m = k = 0; k < n; ++ k) {
                    if (k != i && k != j) {
                        b[m] = a[k];
                        m++;
                    }
                }
                b[m] = a[i] + a[j];
                count(b, m + 1);
                b[m] = a[i] - a[j];
                count(b, m + 1);
                b[m] = a[i] * a[j];
                count(b, m + 1);
                if (a[j] != 0)
                    b[m] = a[i] / a[j];
                count(b, m + 1);
            }
        }
    }
}


int main(){
    double a[4];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0] + a[1] + a[2] + a[3] != 0)) {
        ans = 0;
        count(a, 4);
        if (ans == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}