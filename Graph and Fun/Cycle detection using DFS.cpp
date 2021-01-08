//Cycle detection using DFS
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000];
list<int> *arr;

bool dfsCycledetection(int v,int parent)
{
    visit[v]=1;
    for(int child:arr[v])
    {
        if(visit[child]==0)
        {
            if(dfsCycledetection(child,v)) return true;
        }
        else
        if(child!=parent)
        return true;
    }
    return false;
}

int main()
{
  int v,e,a,b;bool flag=true; cin>>v>>e;
  arr= new list<int>[v];
  for(int i=0;i<e;i++)
  {cin>>a>>b;arr[a-1].push_back(b-1);arr[b-1].push_back(a-1);}
  for(int i=0;i<v;i++)
  if(visit[i]==0)
  flag |= dfsCycledetection(i,i);
  
  if(flag) cout<<"Yes";
  else cout<<"No";
}
