//A very simple program for minimum difference of subset sum using look up table
//DP
//Author : Infra
#include<bits/stdc++.h>
using namespace std;

int main()
{

int cn,sum=0,ans;
cin>>cn;
int a[cn];
for(int i=0;i<cn;i++)
{cin>>a[i];sum+=a[i];}


bool dp[cn+1][sum/2+1];
for(int i=0;i<=cn;i++)
dp[i][0]=true;
for(int i=0;i<=sum/2;i++)
dp[0][i]=false;
for(int i=1;i<=cn;i++)
for(int j=1;j<=sum/2;j++)
{
dp[i][j]=dp[i-1][j];
if(j >= a[i-1])
dp[i][j] |= dp[i-1][j-a[i-1]];
}
for(int i=sum/2;i>=0;i--)
if(dp[cn][i])
{
ans=sum-2*i;
break;
}
cout<<ans;


}
