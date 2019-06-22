#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 77

int w, h;
char map[MAX][MAX];
bool flag[MAX][MAX];
int  direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int minstep;

void search(int curx, int cury, int endx, int endy, int step, int dir){
    if (step > minstep) return;
    if (curx == endx && cury == endy) {
        if (minstep > step)
            minstep = step;
        return;
    }
    for (int i = 0; i < 4; ++ i) {
        int x = curx + direction[i][0];
        int y = cury + direction[i][1];
        if ((x > -1 && x < w + 2) && (y > -1 && y < h + 2) 
            && (!flag[y][x])
            && ((map[y][x] == ' ') || (map[y][x] == 'X' && (x == endx && y == endy)))) {
            flag[y][x] = true;
            if (dir == i) {
                search(x, y, endx, endy, step, dir);
            } else {
                search(x, y, endx, endy, step+1, i);
            }
            flag[y][x] = false;
        }

    }
}

int main(){
    int cases = 1;
    while (true){
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 1; i <= h; ++ i) {
            cin.get();
            for (int j = 1; j <= w; ++ j) {
                map[i][j] = cin.get();
            }
        }
        for (int i = 0; i <= w + 1; ++i) {
            map[0][i] = ' ';
            map[h + 1][i] = ' ';
        }
        for (int i = 0; i <= h + 1; ++i) {
            map[i][0] = ' ';
            map[i][w + 1] = ' ';
        }
        memset(flag, 0, sizeof(flag));
        cout << "Board #" << cases << ":" << endl;
        int num = 1;
        while (true) {
            int x1, y1, x2, y2;
            minstep = 99999;
            cin >> x1 >> y1 >> x2 >> y2;
            if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) 
                break;
            search(x1, y1, x2, y2, 0, -1);
            if (minstep < 99999)
                cout << "Pair " << num << ": " << minstep << " segments." << endl;
            else
                cout << "Pair " << num << ": " << "impossible." << endl;                
            num++;
        }
        cout << endl;
        cases ++;
    }
    return 0;
}