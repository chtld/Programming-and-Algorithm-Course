#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100001

int L[MAXN], C, N;

bool check(int dis) {
    int temp = L[0];
    int count = 1;
    for (int i = 1; i < N; ++ i) {
        if (L[i] - temp >= dis) {
            count++;
            temp = L[i];
            if (count >= C) 
                return true;
        }
    }
    return false;
}

int BinarySearch(){
    int left = 0, right = L[N-1] - L[0], mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (check(mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}


int main(){
    while(scanf("%d %d", &N, &C) != EOF){
        for (int i = 0; i < N; ++ i) {
            scanf("%d", &L[i]);
        }
        sort(L, L + N);
        int ans = BinarySearch();
        printf("%d\n", ans);
    }

    return 0;
}