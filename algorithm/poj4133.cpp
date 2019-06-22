#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 1025

struct point{
    int x, y, num;
};

int main(){
    point p[21];
    int map[MAX][MAX] = {0};
    int d, n;
    int ans = 0, nop = 0;
    cin >> d >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> p[i].x >> p[i].y >> p[i].num;
    }
    for (int i = 1; i <= n; ++ i) {
        for (int row = p[i].x-d; row <= p[i].x+d; row++) {
            if(row >=0 && row < MAX) {
                for (int col = p[i].y - d; col <= p[i].y + d; col++) {
                    if (col >= 0 && col < MAX) {
                        map[row][col] += p[i].num;
                        if (map[row][col] > ans) {
                            ans = map[row][col];
                            nop = 1;
                        } else if (map[row][col] == ans) {
                            ++ nop;
                        }
                    }
                }
            }
        }
    }
    cout << nop << " " << ans;
    return 0;
}