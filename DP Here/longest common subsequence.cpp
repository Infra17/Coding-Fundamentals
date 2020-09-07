//A very simple program for longest common subsequence using look up table
//DP
//Author : Infra
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    string a,b;
    cin>>a>>b;
    for(int i=0;i<=a.length();i++)
        for(int j=0;j<=b.length();j++)
    {
        if(i==0||j==0)
            dp[i][j]=0;
        else if(a[i]==b[j])
            dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    /* If You wanna see the look up table!
    for(int i=0;i<=a.length();i++){
        for(int j=0;j<=b.length();j++)
    {cout<<dp[i][j]<<" ";}cout<<endl;}
    */
    cout<<dp[a.length()][b.length()];
}


                
