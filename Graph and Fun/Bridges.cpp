#include <bits/stdc++.h>
using namespace std;
int v;
int t;
int *Parent,*Visited,*Disc,*Low;
vector<pair<int,int>> BridgesNodes;
void Addedges(int a,int b,vector<int> *Adj)
{
  Adj[a].push_back(b);
  Adj[b].push_back(a);
}

void Bridge(int i,vector<int> *Adj)
{
  Visited[i]=1;
  Disc[i]=Low[i]=++t;
  for(int j=0;j<Adj[i].size();j++)
  {
    int child=Adj[i][j];
    if(Visited[child]==0)
    {
      Parent[child]=i;
      Bridge(child,Adj);
      Low[i]=min(Low[i],Low[child]);
      if(Low[child]>Disc[i])
      BridgesNodes.push_back({i,child});
    }
    else if(child!=Parent[i])
    Low[i]=min(Low[i],Disc[child]);
  }
}

int main()
{
  v=18;
  t=0;
  vector<int> Adj[v];
  Addedges(0,1,Adj);Addedges(0,6,Adj);Addedges(1,7,Adj);Addedges(1,2,Adj);
  Addedges(2,8,Adj);Addedges(2,3,Adj);Addedges(3,9,Adj);Addedges(4,5,Adj);
  Addedges(4,10,Adj);Addedges(5,11,Adj);Addedges(6,7,Adj);Addedges(7,13,Adj);
  Addedges(7,8,Adj);Addedges(8,9,Adj);Addedges(9,15,Adj);Addedges(9,10,Adj);
  Addedges(10,11,Adj);Addedges(11,17,Adj);Addedges(12,13,Adj);Addedges(13,14,Adj);
  Addedges(15,16,Adj);Addedges(10,16,Adj);

  Parent=new int[v];
  Visited=new int[v];
  for(int i=0;i<v;i++) {Parent[i]=-1;Visited[i]=0;}
  Disc=new int[v];
  Low=new int[v];
  for(int i=0;i<v;i++)
  if(Visited[i]==0)
  Bridge(i,Adj);
  cout<<"In the graph, the Bridges are in between :\n";
  for(int i=0;i<BridgesNodes.size();i++)
  cout<<BridgesNodes[i].first<<" "<<BridgesNodes[i].second<<endl;
}
