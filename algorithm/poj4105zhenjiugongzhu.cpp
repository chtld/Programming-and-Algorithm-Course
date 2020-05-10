#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
/*
感谢周洋师弟的帮助；
简单的广搜；
*/
 
struct point
{
    int x, y, s, time;
    point (int xx, int yy, int ss, int tt):x(xx), y(yy), s(ss), time(tt){};
};
 
struct door
{
    int x, y;
}door[15];
 
int r,c,k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int min_time = 0;
char mp[210][210];
bool visited[210][210][1 << 5];//记录特定的发现宝石状态下，特定位置的被访问情况；
 
bool check(int s, int k)
{//s为宝石发现情况；
    int cnt = 0;//记录已发现宝石的个数；
    for (int i = 0; i <= 4; i++)
    {
        if ((s >> i) & 1 == 1)
            cnt++;
    }
    return (cnt >= k);//集齐全部宝石；
}
 
bool bfs(int x, int y, int ex, int ey, int num_door, int k)
{
    queue<point> qu;
    qu.push(point(x, y, 0, 0));
    while (!qu.empty())
    {
        point temp = qu.front();
        qu.pop();
        if (temp.x == ex && temp.y == ey && check(temp.s, k))
        {
            min_time = temp.time;
            return true;
        }
        if (mp[temp.x][temp.y] == '.')
        {
            for (int i = 0; i < 4; i++)
            {
                int sx = temp.x + dx[i];
                int sy = temp.y + dy[i];
                if (sx >= 0 && sx < r && sy >= 0 && sy < c && mp[sx][sy] != '#' && visited[sx][sy][temp.s] == false)
                {
                    visited[sx][sy][temp.s] = true;
                    qu.push(point(sx, sy, temp.s, temp.time + 1));
                }
            }
        }
        if (mp[temp.x][temp.y] >= '0' && mp[temp.x][temp.y] <= '4')
        {
            int s = temp.s | (1 << (mp[temp.x][temp.y] - '0'));
            for (int i = 0; i < 4; i++)
            {
                int sx = temp.x + dx[i];
                int sy = temp.y + dy[i];
                if (sx >= 0 && sx < r && sy >= 0 && sy < c && mp[sx][sy] != '#' && visited[sx][sy][s] == false)
                {
                    visited[sx][sy][s] = true;
                    qu.push(point(sx, sy, s, temp.time + 1));
                }
            }
        }
        if (mp[temp.x][temp.y] == '$')
        {
            for (int i = 0; i < num_door; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    int sx = door[i].x + dx[j];
                    int sy = door[i].y + dy[j];
                    if (sx >= 0 && sx < r && sy >= 0 && sy < c && mp[sx][sy] != '#' && visited[sx][sy][temp.s] == false)
                    {
                        visited[sx][sy][temp.s] = true;
                        qu.push(point(sx, sy, temp.s, temp.time + 1));
                    }
                }
            }
        }
    }
    return false;
}
 
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        memset(visited,0,sizeof(visited));
        int x, y, ex, ey;
        int cnt = 0;//记录传送门的数量；
        cin >> r >> c >> k;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mp[i][j];
                if (mp[i][j] == '$')
                {
                    door[cnt].x = i;
                    door[cnt].y = j;
                    cnt++;
                }
                if (mp[i][j] == 'S')
                {
                    x = i;
                    y = j;
                    mp[i][j] = '.';
                }
                if (mp[i][j] == 'E')
                {
                    ex = i;
                    ey = j;
                    mp[i][j] = '.';
                }
            }
        }
        if (bfs(x, y, ex, ey, cnt, k))
            cout << min_time << endl;
        else
            cout << "oop!" << endl;
    }
    return 0;
}