//Disjoint Set Union
//If the output at the index is negative, that shows how many values are under it. Other wise It will show the value under whom.
//Author:Infra

#include <bits/stdc++.h>
using namespace std;

int *parent,n;

int find(int a)
{
    vector<int> v;
    //cout<<parent[a]<<" ";
    while(parent[a]>=0)
    {
        v.push_back(a);
        a=parent[a];
    }
    for(int i=0;i<v.size();i++)
    parent[v[i]]=a;
    //cout<<parent[a]<<" "<<a<<endl;
    
    
    return a;
}

void uni(int a,int b)  
{
    if(parent[a]>=0||parent[b]>=0) cout<<"PPPPPPPP"<<endl;
    
    parent[a]+=parent[b];
    parent[b]=a;
}

int main()
{
   int m,a,b;cin>>n>>m;
   parent=new int[n+1];
   memset(parent,-1,sizeof(parent));
   for(int i=0;i<n+1;i++)
   parent[i]=-1;
   
   while(m--)
   {
       cin>>a;
       a=find(a);
       cin>>b;b=find(b);
       if(a!=b) uni(min(a,b),max(a,b));
   }
   
   for(int i=0;i<n+1;i++)
   find(i);
   
   for(int i=0;i<n+1;i++)
   cout<<parent[i]<<" ";
   
   return 0;
}
