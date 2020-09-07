//Bipartite Graph Test
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000],colour[1000];
list<int> *arr;
bool dfsbipart(int v,int c)
{
    visit[v]=1;
    colour[v]=c;
    for(int child:arr[v])
    {
        if(visit[child])
        {
            if(colour[v]==colour[child])
            return false;
        }
        else
        if(dfsbipart(child,c^1)==false)
        return false;
    }
    return true;
}

int main()
{
  int v,e,a,b;bool flag=true; cin>>v>>e;
  arr= new list<int>[v];
  for(int i=0;i<e;i++)
  {cin>>a>>b;arr[a-1].push_back(b-1);arr[b-1].push_back(a-1);}
  for(int i=0;i<v;i++)
  if(visit[v]==0)
  flag &= dfsbipart(1,1);
  
  if(flag)cout<<"Yes";
  else cout<<"No";
}
