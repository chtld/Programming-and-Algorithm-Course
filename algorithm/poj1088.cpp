#include<iostream>
#include<algorithm>

using namespace std;

struct Point {
    int r, c;
    int h;
    bool operator <(const Point &b) {
        return h < b.h;
    }
};
int R, C;
int L[105][105];
int field[105][105];
Point point[10010];

int max(int a, int b){
    return (a > b) ? a : b;
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; ++ i) {
        for (int j = 0; j < C; ++ j) {
            cin >> field[i][j]; 
            point[i *C + j].h = field[i][j];
            point[i * C + j].r = i;
            point[i * C + j].c = j;
            L[i][j] = 1;
        }
    }
    sort(point, point + R * C);
    for (int i = 0; i < R * C; ++ i) {
        int r = point[i].r;
        int c = point[i].c;
        if (r > 0 &&  field[r - 1][c] < field[r][c])
            L[r][c] = max(L[r][c], L[r - 1][c] + 1);
        if (r < R - 1 && field[r + 1][c] < field[r][c])
            L[r][c] = max(L[r][c], L[r + 1][c] + 1);
        if (c > 0 && field[r][c - 1] < field[r][c])
            L[r][c] = max(L[r][c], L[r][c - 1] + 1);
        if (c < C - 1 && field[r][c + 1] < field[r][c])
            L[r][c] = max(L[r][c], L[r][c + 1] + 1);
    }
    int maxLen = 0;
    for (int i = 0; i < R; ++ i) {
        for (int j = 0; j < C; ++ j) {
            maxLen = max(maxLen, L[i][j]);
        }
    }
    cout << maxLen << endl;
    return 0;
}