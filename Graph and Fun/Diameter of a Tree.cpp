//Diameter of a Tree
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000];
list<int> *arr;
int maxd,maxv;
void dfsfarest(int v,int d)
{
    visit[v]=1;
    //cout<<v<<" "<<d<<" ";
    if(d>maxd) maxd=d,maxv=v;
    for(int child:arr[v])
    if(visit[child]==0)
    dfsfarest(child,d+1);
}

int main()
{
  int v,a,b;bool flag=true; cin>>v;
  arr= new list<int>[v];
  for(int i=0;i<v-1;i++)
  {cin>>a>>b;arr[a-1].push_back(b-1);arr[b-1].push_back(a-1);}
  maxd=maxv=0;
  dfsfarest(0,0);maxd=0;
  memset(visit,0,sizeof(visit));
  dfsfarest(maxv,0);
  
  cout<<maxd;
  
}
