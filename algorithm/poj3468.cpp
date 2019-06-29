#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
    int N, maxv = 0, tot = 0, temp;
    while (cin >> N) {
        maxv = 0, tot = 0;
        while (N--) {
            cin >> temp;
            maxv = max(maxv, temp);
            tot += temp;
        }
        if ((tot - maxv) < maxv)
            printf("%.1lf\n", (double)(tot - maxv));
        else
            printf("%.1lf\n", 1.0*tot/2.0);
    }
    return 0;
}