#include<stdio.h>
#include<iostream>

using namespace std;
long long F[20000][4];//必须优化储存方式以防MLE 
int t[4];//VV:0,VL:1,LV:2,LL:3

inline int g(int x,int y,int z,int w)
{
    return (((x*(t[1]+1)+y)*(t[2]+1)+z)*(t[3]+1)+w);
}

long long f(int* num,int k,int goal)
{
    if (num[0]<0 || num[1]<0 || num[2]<0 || num[3]<0)
        return 0;
    if (F[g(num[0],num[1],num[2],num[3])][goal]!=-1)
        return F[g(num[0],num[1],num[2],num[3])][goal];
    if (k==1)
        return (num[goal]>0);
    int temp[4]={num[0],num[1],num[2],num[3]};
    int l=goal&2,r=goal&1;
    temp[l]--;
    F[g(num[0],num[1],num[2],num[3])][goal]=f(temp,k-1,r);
    temp[l]++;
    temp[l+1]--;
    F[g(num[0],num[1],num[2],num[3])][goal]+=f(temp,k-1,2+r);
    return F[g(num[0],num[1],num[2],num[3])][goal];
}

int main()
{
    int n,k,goal;
    char c1,c2;
    while (cin >> n >> k)
    {
        cin >> c1 >> c2;
        for (int i=0;i<20000;i++)   
            F[i][0]=F[i][1]=F[i][2]=F[i][3]=-1;
        t[0]=t[1]=t[2]=t[3]=0;
        goal=((c2=='L')<<1)+(c1=='L');//要求适配 
        for (int i=1;i<=n;i++)
        {
            cin >> c1 >> c2;
            t[((c1=='L')<<1)+(c2=='L')]++;
        }
        long long ans=f(t,k,goal);
        if (ans)
            printf("YES\n%lld\n",ans);
        else
            printf("NO\n");
    }
    return 0;
}