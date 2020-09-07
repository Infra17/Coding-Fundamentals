//A simple DP table for Nth Catalan Numbers
#include<bits/stdc++.h>
typedef long long int lld;
#define mod 1000000007
using namespace std;
lld catalan[10000];
int main()
{
    int n;cin>>n;
    catalan[0]=catalan[1]=1;
    for(int i=2;i<=n;i++)
    {
        catalan[i]=0;
        
        for(int j=0;j<i;j++)
            catalan[i]+=catalan[j]*catalan[i-j-1];
    }

    cout<<catalan[n];
}
