#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

#define MAXN 60

int R, C;
int room[MAXN][MAXN];
int color[MAXN][MAXN];
int maxRoomArea = 0;
int colorNum = 0;
int roomArea;

struct Room{
    int r, c;
    Room(int rr, int cc) : r(rr), c(cc) { }
};

void dfs(int r, int c){
    stack<Room> stk;
    stk.push(Room(r, c));
    while (!stk.empty()) {
        Room rm = stk.top();
        int rr = rm.r;
        int cc = rm.c;
        if (color[rr][cc])
            stk.pop();
        else {
            ++roomArea;
            color[rr][cc] = colorNum;
            if ((room[rr][cc] & 1) == 0) stk.push(Room(rr, cc - 1));
            if ((room[rr][cc] & 2) == 0) stk.push(Room(rr - 1, cc));
            if ((room[rr][cc] & 4) == 0) stk.push(Room(rr, cc + 1));
            if ((room[rr][cc] & 8) == 0) stk.push(Room(rr + 1, cc));
        }
    }
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