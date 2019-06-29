#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 100000
int n, m;
int a[MAX];

void BinarySearch(){
    for (int i = 0; i < n; ++ i) {
        if (a[i] > m/2) {
            printf("No\n");
            return;
        }
        int target = m - a[i];
        int left = i + 1, right = n, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (a[mid] == target) {
                break;
            } else if (a[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < right) {
            printf("%d %d\n", a[i], a[mid]);
            return;
        }
    }
    printf("No\n");
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    sort(a, a + n);
    BinarySearch();
    return 0;
}