#include<iostream>
#include<cmath>
using namespace std;

double BinarySearch(double left, double right) {
    double mid, f;
    while (right - left > 1e-11) {
        mid = left + (right - left)/2.;
        f = pow(mid,3)-5*pow(mid,2)+10*mid-80;
        if ( f < 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return mid;
}

int main(){
    double left = 0., right = 10.;
    double ans = BinarySearch(left, right);
    printf("%.9lf\n", ans);
    return 0;
}