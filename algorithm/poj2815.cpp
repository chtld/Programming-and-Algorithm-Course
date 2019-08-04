#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 60

int R, C;
int room[MAXN][MAXN];
int color[MAXN][MAXN];
int maxRoomArea = 0;
int colorNum = 0;
int roomArea;

void dfs(int r, int c){
    if (color[r][c]) 
        return;
    ++roomArea;
    color[r][c] = colorNum;
    if ((room[r][c] & 1) == 0) dfs(r, c - 1);
    if ((room[r][c] & 2) == 0) dfs(r - 1, c);
    if ((room[r][c] & 4) == 0) dfs(r, c + 1);
    if ((room[r][c] & 8) == 0) dfs(r + 1, c);
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; ++ i) {
        for (int j = 0; j < C; ++ j) {
            cin >> room[i][j];
        }
    }
    memset(color, 0, sizeof(color));
    for (int i = 0; i < R; ++ i) {
        for (int j = 0; j < C; ++ j) {
            if (!color[i][j]) {
                roomArea = 0;
                colorNum++;
                dfs(i, j);
                maxRoomArea = max(maxRoomArea, roomArea);
            }
        }
    }
    cout << colorNum << endl << maxRoomArea << endl;
    return 0;
}