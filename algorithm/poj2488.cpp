#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 27;
const int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
bool visited[MAXN][MAXN];
struct Step {
    char x, y;
};
Step path[MAXN];
bool success;
int cases, p, q;

void dfs(int x, int y, int num) {
    path[num].y = y + 'A' - 1;
    path[num].x = x + '0';
    if (num == p * q) {
        success = true;
        return;
    }
    for (int i = 0; i < 8; ++ i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 < nx && nx <= p && 0 < ny && ny <=q && !visited[nx][ny] && !success) {
            visited[nx][ny] = true;
            dfs(nx, ny, num + 1);
            visited[nx][ny] = false;
        }
    }
}


int main(){
    cin >> cases;
    for (int i = 1; i <= cases; ++ i) {
        cin >> p >> q;
        memset(visited, 0, sizeof (visited));
        success = false;
        visited[1][1] = true;
        dfs(1, 1, 1);
        cout << "Scenario #" << i << ":" << endl;
        if (success) {
            for (int i = 1; i <= p * q; ++ i) {
                cout << path[i].y << path[i].x;
            }
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }
        if (i != cases)
            cout << endl;     
    }
    return 0;
}