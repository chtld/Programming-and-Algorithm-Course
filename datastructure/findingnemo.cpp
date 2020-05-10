#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
//#include <map>
#include <set>
using namespace std;
/***************************************/
#define ll long long
#define int64 __int64
/***************************************/
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const double PIE=acos(-1.0);
const int d1x[]= {0,-1,0,1};
const int d1y[]= {-1,0,1,0};
const int d2x[]= {0,-1,0,1};
const int d2y[]= {1,0,-1,0};
const int fx[]= {-1,-1,-1,0,0,1,1,1};
const int fy[]= {-1,0,1,-1,1,-1,0,1};
/***************************************/
void openfile()
{
    freopen("data.in","rb",stdin);
    freopen("data.out","wb",stdout);
}
/**********************华丽丽的分割线,以上为模板部分*****************/
int map[300][300][2];  //存储图
int vis[300][300],cnt[300][300]; //cnt计数
int maxx,maxy;
int sum;
struct node
{
    int x,y;
    bool operator < (const node &n1)const   //优先队列从小到大排
    {
        return cnt[n1.x][n1.y]<cnt[x][y];
    }
};
void BFS(int f1,int f2)
{
    priority_queue<node >Q;
    int i,j;
    int x,y;
    node ce;
    for(i=0; i<=maxx; i++)
        for(j=0; j<=maxy; j++)
            cnt[i][j]=INF;   //因为需要判断这个格子是否走过，用到最短路的这个点的cnt值加上map值是否小于i，j这个点的cnt值。
    cnt[0][0]=0;
    ce.x=0;
    ce.y=0;
    Q.push(ce);
    while(!Q.empty())
    {
        ce=Q.top();
        Q.pop();
        x=ce.x;
        y=ce.y;
        if (x==f1&&y==f2)
        {
            sum=cnt[x][y];
            return ;
        }
        if (y+1<=maxy&&cnt[x][y+1]>cnt[x][y]+map[x][y+1][0])  //向上走时是交于x，y+1的右方向的边
        {
            cnt[x][y+1]=cnt[x][y]+map[x][y+1][0];  
            ce.x=x;
            ce.y=y+1;
            Q.push(ce);
        }
        if (y-1>=0&&cnt[x][y-1]>cnt[x][y]+map[x][y][0])  //向下走时是交于x，y的右方向的边
        {
            cnt[x][y-1]=cnt[x][y]+map[x][y][0];
            ce.x=x;
            ce.y=y-1;
            Q.push(ce);
        }
        if (x+1<=maxx&&cnt[x+1][y]>cnt[x][y]+map[x+1][y][1])//向右走时是交于x+1，y的上方向的边
        {
            cnt[x+1][y]=cnt[x][y]+map[x+1][y][1];
            ce.x=x+1;
            ce.y=y;
            Q.push(ce);
        }
        if (x-1>=0&&cnt[x-1][y]>cnt[x][y]+map[x][y][1])//向左走时是交于x，y的上方向的边
        {
            cnt[x-1][y]=cnt[x][y]+map[x][y][1];
            ce.x=x-1;
            ce.y=y;
            Q.push(ce);
        }
    }
    sum=-1;
    return ;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if (m==-1&&n==-1)
            break;
        sum=0;
        int i,j;
        int x,y,d,t;
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        maxx=-1;
        maxy=-1;
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&x,&y,&d,&t);
            for(j=0; j<t; j++)
            {
                if (d)  //1 代表 向上的方向标记，0则相反。
                {
                    map[x][y+j][d]=INF;  //标记为墙
                    maxx=max(maxx,x);  //找格子最大的x坐标
                    maxy=max(maxy,y+t);//找格子最大的y坐标
                }
                else
                {
                    map[x+j][y][d]=INF;
                    maxx=max(maxx,x+t);
                    maxy=max(maxy,y);
                }
            }
        }
        int x1,y1,d1;
        for(i=0; i<n; i++)
        {
            scanf("%d%d%d",&x1,&y1,&d1);
                map[x1][y1][d1]=1;  //标记为门
        }
        double f1,f2;
        scanf("%lf%lf",&f1,&f2);
        if(f1>maxx||f2>maxy)
        {
            printf("0\n");
            continue;
        }
        BFS(f1,f2);
        printf("%d\n",sum);
    }
    return 0;
}