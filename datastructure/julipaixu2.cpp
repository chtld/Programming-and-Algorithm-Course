#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
 
struct point{
    int x,y,z;
}P[200];
struct ANS{
    int h1,h2;
    double juli;
}J[10100];
double ce(point a1,point a2)
{
    return sqrt((a1.x-a2.x)*(a1.x-a2.x)+(a1.y-a2.y)*(a1.y-a2.y)+(a1.z-a2.z)*(a1.z-a2.z));
}
 
bool cmp(ANS a1,ANS a2)
{
    if(a1.juli!=a2.juli)return a1.juli>a2.juli;
    else if(a1.h1!=a2.h1)return a1.h1<a2.h1;
    else return a1.h2<a2.h2;
}
 
int main(){
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&P[i].x,&P[i].y,&P[i].z);
    }
    int j;
    int cnt=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            J[cnt].h1 = i;
            J[cnt].h2 = j;
            J[cnt++].juli = ce(P[i],P[j]);
        }
        sort(J,J+cnt,cmp);
        for(i=0;i<cnt;i++)
        {
            printf("(%d,%d,%d)-(%d,%d,%d)=%.2lf\n",P[J[i].h1].x,P[J[i].h1].y,P[J[i].h1].z,P[J[i].h2].x,P[J[i].h2].y,P[J[i].h2].z,J[i].juli);
        }
 
    return 0;
}