#include<iostream>
#include<string.h>
using namespace std;
int dp1[51][51], dp2[51][51], dp3[51][51];
int n,k;
int main()
{
	int i,j;
	while(cin>>n>>k)
	{
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(dp3,0,sizeof(dp3));
		//Q1，将n划分为k个正整数
		dp1[0][0]=1;
		for (i=1;i<=n;i++)//和
			for (j=1;j<=i;j++)//划分为j个数，注意边界条件！！
				dp1[i][j]=dp1[i-j][j]+dp1[i-1][j-1]; //dp1[i-j][j]意思是把i-j划分为j个不同的数，然后每个数+1
		cout<<dp1[n][k]<<endl;
		//Q2,把n划分为若干不同的正整数的个数
		dp2[0][0]=1;
		for (i=1;i<=n;i++)//和
			for (j=1;j<=n;j++)//划分的数字在1~j范围内
			{
				if (j==i)
					dp2[i][j]=dp2[i][j-1]+1;
				else if (j>i)
					dp2[i][j]=dp2[i][i];
				else
					dp2[i][j]=dp2[i-j][j-1]+dp2[i][j-1];//唯一的不同，dp2[i-j][j-1]
			}
		cout<<dp2[n][n]<<endl;
		//Q3:n划分成若干个奇正整数之和的划分数目
		dp3[0][0]=1;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)//划分的数字在1~j范围内
			{
				if (j%2==0)//假如是偶数则往下递推
					dp3[i][j]=dp3[i][j-1];
				else if (i<j)//是奇数则计算方法同简单的整数划分
					dp3[i][j]=dp3[i][i];
				else if (i==j)
					dp3[i][j]=dp3[i][j-1]+1;
				else
					dp3[i][j]=dp3[i-j][j]+dp3[i][j-1];
			}
		cout<<dp3[n][n]<<endl;
	}
    return 0;
}
