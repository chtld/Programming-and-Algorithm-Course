/* 思路：枚举所有路径，从中选出最长的路径
** (1) 做到尽可能每种情况只枚举一次
** (2) 迅速排除某些不满足条件的路径
** 步骤：
** (1) 建立点的结构体，将所有点的坐标进行记录，
**     对点的位置进行排序，使得每条可能路径只枚举一次
** (2) 用一个布尔矩阵记录田间被踩踏的水稻
** (3) 枚举所有可能路径进行判断，要注意对某些路径尽快排除，
**     比如，前一个点落在稻田之外，最后一棵水稻的后一个点
**     落在稻田之外, 已知最好的答案为 result, 但经过 result - 1
**     步就到了稻田之外
 */


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 5001
struct point{
    int x;
    int y;
};
int R, C, N;
int result = 0;
bool flag[MAXN][MAXN];
point p[MAXN];

bool operator<(const point &a, const point &b){
    return (a.x < b.x || (a.x == b.x) && a.y < b.y);
}

bool isOutside(int x, int y){
    if (x < 1 || x > R || y < 1 || y > C) {
        return true;
    } else {
        return false;
    }
}

bool count(int a, int b){
    int dx = p[b].x - p[a].x;
    int dy = p[b].y - p[a].y;
    if (!isOutside(p[a].x - dx, p[a].y - dy)) {
        return false;
    }
    if (isOutside(p[a].x + result * dx, p[a].y + result * dy)) {
        return false;
    }
    int k = 2;
    int x1 = p[b].x + dx;
    int y1 = p[b].y + dy;
    while (!isOutside(x1, y1) && flag[x1][y1]) {
        ++ k;
        x1 += dx;
        y1 += dy;
    }
    if (isOutside(x1, y1) && k > result) {
        result = k;
    }
    return true;
}

int main(){
    scanf("%d %d %d", &R, &C, &N);
    for (int i = 0; i < N; ++ i) {
        scanf("%d %d", &p[i].x, &p[i].y);
        flag[p[i].x][p[i].y] = true;
    }
    sort(p, p + N);
    for (int i = 0; i < N; ++ i) {
        for (int j = i; j < N; ++ j) {
            count(i, j);
        }
    }
    if (result < 3) {
        result = 0;
    }
    printf("%d\n", result);
    return 0;
}