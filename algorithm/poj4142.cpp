#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double BinarySearch(double left, double right) {
    double mid;
    while (right - left > 1e-6) {
        mid = left + (right - left) / 2;
        double f = pow(mid, 5) - 15 * pow(mid, 4) + 85 * pow(mid, 3) - 225 * pow(mid, 2) + 274 * mid -121;
        if (f < 0)
            right = mid;
        else
            left = mid;
    }
    return mid;
}


int main(){
    double left = 1.5, right = 2.4;
    double ans = BinarySearch(left, right);
    printf("%.6lf\n", ans);
    return 0;
}