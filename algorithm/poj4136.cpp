#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 10000

struct Rectangle{
    int L, T, W, H;
};

int R, N;
Rectangle rectangle[MAX];

long long check(int mid) {
    long long leftarea = 0, rightarea = 0;
    for (int i = 0; i < N; ++ i) {
        if(rectangle[i].L + rectangle[i].W <= mid) {
            leftarea += rectangle[i].W * rectangle[i].H;
        } else if (rectangle[i].L >= mid) {
            rightarea += rectangle[i].W * rectangle[i].H;
        } else {
            leftarea += (mid - rectangle[i].L) * rectangle[i].H;
            rightarea += (rectangle[i].L + rectangle[i].W - mid) * rectangle[i].H;
        }
    }
    return (leftarea - rightarea);
}

int BinarySearch(){
    int left = 0, right = R, mid = 0;
    while(left <= right) {
        mid = left + (right - left) / 2;
        if (check(mid) < 0) {
            left = mid + 1;
        } else if (check(mid) > 0){
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return left;
}

int main(){
    scanf("%d", &R);
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) {
        scanf("%d %d %d %d", &rectangle[i].L, &rectangle[i].T, &rectangle[i].W, &rectangle[i].H);
    }
    if((N == 1 && rectangle[0].W == 1) || (N == 0)) {
        printf("%d\n", R);
        return 0;
    }
    int ans = BinarySearch();
    for (int i = ans; (i < R  &&  check(ans) == check(ans + 1)); ++ i){
        ans ++;    
    }  
    printf("%d\n", ans);
    return 0;
}