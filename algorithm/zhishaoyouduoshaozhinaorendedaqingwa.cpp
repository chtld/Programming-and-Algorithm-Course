#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=55;
int n,m,k;
int Map[maxn][maxn];

struct Point {
    int x,y;
    Point() {}
    Point(int _x,int _y):x(_x),y(_y) {}
    bool operator < (const Point &b) const {
        if(x!=b.x) return x<b.x;
        return y<b.y;
    }
}p[705];

struct Frog {
    int x,y,cnt,dx,dy,next;
    Frog() {}
    Frog(int _x,int _y,int _v,int _dx,int _dy,int nx):x(_x),y(_y),cnt(_v),dx(_dx),dy(_dy),next(nx) {}
    bool operator < (const Frog &b) const {
        return cnt>b.cnt;
    }
}op[705*705];

int tot=0,head[maxn][maxn];
int sum=0;
void add_frog(int x,int y,int v,int dx,int dy) {
    for(int i=head[x][y];~i;i=op[i].next) if(op[i].dx==dx && op[i].dy==dy) return;
    //用邻接表对于特征相同的元素进行去重
    op[++tot]=Frog(x,y,v,dx,dy,head[x][y]), head[x][y]=tot;
    return;
}

void init() {
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        Map[i][j]=0, head[i][j]=-1;
    tot=0; sum=0;
    return;
}

inline bool inrange(const int &x,const int &y) {
    if(x<1 || y<1 || x>n || y>m) return false;
    return true;
}

int lit;
bool dfs(int dep,int last) {
    if(dep==lit) {
        if(!sum) return true;
        return false;
    }
    if(op[last].cnt*(lit-dep)<sum) return false; //可行性剪枝，如果无论如何都达不到就剪掉
    register int i,x,y,dx,dy;
    for(i=last;i<=tot;++i) { //搜索的时候改为枚举本质不同的路径
        x=op[i].x, y=op[i].y, dx=op[i].dx, dy=op[i].dy;
        bool flag=true;
        for(;flag && inrange(x,y);x+=dx,y+=dy)
            if(!Map[x][y]) flag=false;
        if(!flag) continue; //检验路径是否仍然可用
        for(x-=dx,y-=dy;inrange(x,y);x-=dx,y-=dy)
            --Map[x][y]; //处理路径
        sum-=op[i].cnt;
        if(dfs(dep+1,i)) return true;
        for(x+=dx,y+=dy;inrange(x,y);x+=dx,y+=dy)
            ++Map[x][y]; //还原路径
        sum+=op[i].cnt;
    }
    return false;
}

void work() {
    scanf("%d%d%d",&n,&m,&k);
    init();
    for(int cnt,i=1;i<=k;i++) {
        scanf("%d%d%d",&p[i].x,&p[i].y,&cnt);
        sum+=cnt;
        Map[p[i].x][p[i].y]+=cnt; //读入并处理被糟蹋的总数和各个点被糟蹋的次数
    }
    sort(p+1,p+1+k); //将所有点按横纵坐标排序，达到去重的作用（因为一条路径可能分为正反两向）

    register int i,j,x,y,u,v;
    for(i=1;i<=k;++i)
    for(j=i+1;j<=k;++j) {
        x=p[i].x, y=p[i].y, u=p[j].x, v=p[j].y;
        register int p1,p2,dx=u-x, dy=v-y;
        int flag=true, cnt=0;
        for(p1=x-dx,p2=y-dy;flag && inrange(p1,p2);p1-=dx,p2-=dy)
            if(Map[p1][p2]) flag=false;
        if(!flag) continue;
        for(p1=x,p2=y;flag && inrange(p1,p2);p1+=dx,p2+=dy)
            if(Map[p1][p2]) cnt++;
            else flag=false;
        if(!flag || cnt<3) continue; //不合法的路径直接去掉
        add_frog(x,y,cnt,dx,dy);
    }
    sort(op+1,op+1+tot); //优先枚举占点个数多的路径

    lit=1;
    while(lit<=14) { //仍然选择迭代加深搜索
        if(dfs(0,1)) {
            printf("%d\n",lit);
            return;
        } else lit++;
    }
}

int main() {
// #ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
// #endif // ONLINE_JUDGE
    int cas;
    scanf("%d",&cas);
    while(cas--) work();

    return 0;
}