#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 10005

int a[MAXN], b[MAXN];
double y[MAXN];
int n, k;

bool check(double v) {
    double sum = 0;
    for (int i = 0; i < n; ++ i) {
        y[i] = a[i] - v*b[i];
    }
    sort(y, y + n);
    for (int i = k; i < n; ++ i) {
        sum += y[i];
    }
    if (sum >= 0) return true;
    else return false;
}

double BinarySearch(double left, double right) {
    double mid;
    while (right - left > 1e-5) {
        mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}

int main(){
    while (scanf("%d %d", &n, &k) != EOF)
    {
        if (n == 0 && k == 0) break;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++ i) {
            scanf("%d", &b[i]);
        }
        double ans = BinarySearch(0, 1);
        printf("%.0lf\n", (ans * 100));
    }
    
    return 0;
}