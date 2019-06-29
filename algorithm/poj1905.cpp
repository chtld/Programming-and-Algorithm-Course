#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double L, n, C, h;

double BinarySearch(){
    double left = 0., right = 0.5 * L, mid;
    double r, La, f;
    La = (1 + n * C) * L;
    while (right - left >= 1e-11) {
        mid = left + (right - left) / 2.;
        r = mid/2. + L * L / (8 * mid);
        f = 2. * r * asin(L / 2 / r);
        if (abs(f-La) < 1e-11)
            break;
        else if (f < La) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

int main(){
    while (true) {
        scanf("%lf %lf %lf", &L, &n, &C);
        if (abs(L + 1) <= 1e-11 && abs(n + 1) <= 1e-11 && abs(C + 1) <= 1e-11)
            break;
        h = BinarySearch();
        printf("%.3lf\n", h);
    }
    return 0;
}