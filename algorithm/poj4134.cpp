#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[100001], n, m;

int BinarySearch(int target) {
    int left = 0;
    int right = n;
    int mid;
    if (target <= a[0]) return a[0];
    if (target >= a[n - 1]) return a[n - 1];
    while (left < right) {
        mid = left + (right - left) / 2;
        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (abs(a[left] - target) < abs(a[left - 1] - target)) {
        return a[left];
    } else {
        return a[left - 1];
    }
}

int main(){
    int target;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d", &target);
        int ans = BinarySearch(target);
        printf("%d\n", ans);
    }
    return 0;
}