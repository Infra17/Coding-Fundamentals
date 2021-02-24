#include <bits/stdc++.h>
using namespace std;
int v;
vector<int> TopSorted;
vector<pair<int,int>> EdgeCanBeAdded;

void Addedges(int a,int b,vector<int> *Adj,int *directedTo)
{
    Adj[a].push_back(b); // Directed
    directedTo[b]++; // Tracing how many edges are directed to b
}

void Kahn(vector<int> *Adj,int *directedTo)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    // We could use just Queue to track which nodes we get as most independent
    // Instead using PQ (Min Heap) to get unique sorted solution
    for(int i=0;i<v;i++)
    if(directedTo[i]==0) {pq.push(i);}
    //Most independent nodes

    while(!pq.empty())
    {
        int current=pq.top(); // top node
        TopSorted.push_back(current);
        pq.pop();
        for(int i=0;i<(int)Adj[current].size();i++)
        {// How many nodes we can go for thi top node
            directedTo[Adj[current][i]]--;
            if(directedTo[Adj[current][i]]==0)
            pq.push(Adj[current][i]);
        }

    }
}

void MaxEdgeAdd(vector<int> *Adj)
{
    bool *visit=new bool[v]; // Taking a visit array
    for(int i=0;i<v;i++)
    {
        int temp=TopSorted[i];
        for(int j=0;j<Adj[temp].size();j++)
        visit[Adj[temp][j]]=true;
        // Marking thr nodes we can go from i visited
        for(int j=i+1;j<v;j++)
        {if(!visit[TopSorted[j]]) EdgeCanBeAdded.push_back({temp,TopSorted[j]});
        // If it is not visited, we can add it
        //and we have to mark it unvisited if another node can not visit it
        visit[TopSorted[j]]=false;
        }
    }
}

int main()
{
    v=6;
    int *directedTo=new int[v];
    // To track how many edges is directed to the node
    // Hence how many nodes are dependent on the respective node
    for(int i=0;i<v;i++)
    directedTo[i]=0;
    vector<int> Adj[v]; // Adjacency List
    Addedges(0,5,Adj,directedTo);Addedges(1,3,Adj,directedTo);Addedges(3,2,Adj,directedTo);
    Addedges(1,2,Adj,directedTo);Addedges(5,1,Adj,directedTo);Addedges(4,5,Adj,directedTo);

    Kahn(Adj,directedTo);
    if(TopSorted.size()!=v)
    {cout<<"Not a Directed Acyclic Graph.";return 0;}
    // You may find a cycle
    else
    {
    cout<<"The Topologically sorted order of the nodes are:\n";
    for(int i=0;i<(int)TopSorted.size();i++)
    {
        cout<<TopSorted[i]<<" ";}
    }
    MaxEdgeAdd(Adj);
    cout<<"\nFollowing is the edges can be added\n";
    for(int i=0;i<(int)EdgeCanBeAdded.size();i++)
    {cout<<EdgeCanBeAdded[i].first<<" directing towards "<<EdgeCanBeAdded[i].second<<endl;}
}



