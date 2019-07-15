#include<iostream>
#include<cstdio>

using namespace std;

int n, a[100000], k;
int left1 = 0;
int right1 = 0;
int mid;

bool check(int ans) {
    int now = 0;
    for (int i = 0; i < n; ++ i) {
        if (a[i] > ans) {
            now += (a[i] - ans - 1) / (k - 1) + 1;
            if (now > ans) return false;
        }
    }
    return true;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        if (a[i] > right1) right1 = a[i];
    }
    cin >> k;
    if (k == 1) printf("%d\n", right1);
    else {
        while (left1 <= right1) {
            mid = left1 + (right1 - left1) / 2;
            if (check(mid))  right1 = mid - 1;
            else left1 = mid + 1;
        }
        printf("%d\n", left1);
    }
    return 0;
}