//A very simple program for egg dropping problem minimum number of attends for worst case
//DP
//Author : Infra
//Input : 2 10 / 2 36 / 100 2000
//Output : 4 / 8 / 11
#include<bits/stdc++.h>
using namespace std;
int dp[1000][10000];
int lookup[1000][10000];
//Memoization
int func(int e,int f)
{
    if(dp[e][f]!=-1)
    return dp[e][f];

    if(f==0||f==1)
        return dp[e][f]=f;
    else if(e==1)
        return dp[e][f]=f;

    int mn=INT_MAX;
    for(int k=1;k<=f;k++)
    {
        int temp=1+max(func(e-1,k-1),func(e,f-k));
        mn=min(mn,temp);
    }
    return dp[e][f]=mn;

}

int main()
{
    memset(dp,-1,sizeof(dp));
   // memset(lookup,0,sizeof(lookup));
    int eggs,floors;
    //cin>>eggs>>floors;
    eggs=100;floors=2000;
    //Tabulation
    for(int i=1;i<=eggs;i++)
    {
        lookup[i][1]=1;lookup[i][0]=0;
    }
    for(int i=1;i<=floors;i++)
        {lookup[1][i]=i;}

    for(int i=2;i<=eggs;i++)
        for(int j=2;j<=floors;j++)
    {
        lookup[i][j]=INT_MAX;
        for(int k=1;k<=j;k++)
        {
            int temp=1+max(lookup[i-1][k-1],lookup[i][j-k]);
            lookup[i][j]=min(lookup[i][j],temp);
        }
    }




    cout<<func(eggs,floors); //M
    cout<<endl;
    cout<<lookup[eggs][floors]; //T
}
