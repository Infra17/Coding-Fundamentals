//Author : Infra
#include <bits/stdc++.h>
using namespace std;

DFS_Func(int root,vector<int> *Adj)
{
    if(Adj[root].size()==0) return 0;
    int Y=1;
    for(auto i:Adj[root])
    Y+=DFS_Func(i,Adj);

    int N=0;
    for(auto i:Adj[root])
    {N+=1;
        for(auto j:Adj[i])
        N+=DFS_Func(j,Adj);
    }
    return min(Y,N);
}

int main()
{
    int v,a,b,root;cin>>v;
    vector<int> Adj[v],Out(v),In(v);
    for(int i=0;i<v-1;i++)
    {
        cin>>a>>b;
        Adj[a].push_back(b);
        In[b]++;
    }
    for(int i=0;i<v;i++)
    if(In[i]==0) {root=i;break;}
    cout<<DFS_Func(root,Adj);
}

/*
This is a problem such that we have a binary tree and we need to make a set, such that
It will contain either the starting or the ending of all the edges given or both.
Its size will be as minimum as possible.
So this code will print the size of it.
*/
