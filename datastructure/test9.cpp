#include <cstdio>
using namespace std;
int main()
{
    int i,j,dp[2][10086],n;
    int a[10086],b[10086];
    bool now,pre;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++ i) {
        cin >> str1[i];
    }
    for (int i = 1; i <= n; ++ i) {
        cin >> str2[i];
    }
    memset(dp,0,sizeof(dp));
    int lena=strlen(a),lenb=strlen(b);
    for(now=1,pre=0,i=0; i<lena; i++)
        for(swap(now,pre),j=0; j<lenb; j++)
            if(a[i]==b[j])
                dp[now][j+1]=dp[pre][j]+1;
            else
                dp[now][j+1]=dp[pre][j+1]>dp[now][j]?dp[pre][j+1]:dp[now][j];
    printf("%d\n",dp[now][lenb]);
    return 0;
}