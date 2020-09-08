//Minimum distance using BFS from 1st to last node
//Non Recursive
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000],dis[1000];
list<int> *arr;

void BFSdistance(int v)
{
    queue<int> q;
    q.push(v);
    visit[v]=1;dis[v]=0;
    
    while(!q.empty())
    {
        int curr=q.front();q.pop();
        for(int child:arr[curr])
        if(visit[child]==0) 
        q.push(child),dis[child]=dis[curr]+dis[child],visit[child]=1;
    }
    
}

int main()
{
  int v,e,a,b;bool flag=true; cin>>v>>e;
  arr= new list<int>[v];
  for(int i=0;i<e;i++)
  {cin>>a>>b;arr[a-1].push_back(b-1);arr[b-1].push_back(a-1);}
  BFSdistance(0);
  cout<<dis[v-1];
}
