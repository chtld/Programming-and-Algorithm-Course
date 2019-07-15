#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int a[1000], b[1000];
    int n;
    int tstart, tend;
    int qstart, qend;
    int count = 0;
    while (cin >> n) {
        if (n == 0) break;
        tstart = 0;
        qstart = 0;
        tend = n - 1;
        qend = n - 1;
        count = 0;
        for (int i = 0; i < n; ++ i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++ i) {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for (int i = n - 1; i >= 0; -- i) {
            if (a[tend] > b[qend]) {
                count++;
                tend--;
                qend--;
            } else if (a[tend] < b[qend]) {
                count--;
                tstart++;
                qend--;
            } else {
                if (a[tstart] > b[qstart]) {
                    count++;
                    tstart++;
                    qstart++;
                } else {
                    if (a[tstart] < b[qend])
                        count--;
                    tstart++;
                    qend--;
                }
            }
        }
        cout << count*200 << endl;
    }
    return 0;
}