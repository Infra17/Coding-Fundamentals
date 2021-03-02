#include <bits/stdc++.h>
using namespace std;
int v;
vector<pair<int,int>> *Adj;
void Addedges(int a,int b, int w)
{
    Adj[a].push_back({b,w});
    Adj[b].push_back({a,w});
}

vector<int> Dijkstra(int source)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance(v,INT_MAX);
    pq.push({0,source});
    distance[source]=0;
    while(!pq.empty())
    {
        int temp = pq.top().second; // w from the pair
        pq.pop();
        for(int i=0;i<(int)Adj[temp].size();i++)
        {
            int temp2=Adj[temp][i].first;
            int w=Adj[temp][i].second;
        
        if(distance[temp2]>distance[temp]+w)
        {
            distance[temp2]=distance[temp]+w;
            pq.push({distance[temp2],temp2});
        }
        }
    }

    return distance;
}

int main()
{
    v=9;
    Adj=new vector<pair<int,int>>[v];
    Addedges(0,1,6); Addedges(1,4,5); Addedges(0,3,1);
    Addedges(3,4,8); Addedges(6,3,3); Addedges(7,4,4);
    Addedges(6,7,2); Addedges(3,7,3); Addedges(1,7,2);
    Addedges(3,5,9); Addedges(2,5,2); Addedges(1,2,8);
    Addedges(5,8,4); Addedges(7,8,7); Addedges(1,5,6);
    Addedges(7,5,5);
    vector<int> ans=Dijkstra(0); // Source here is 0
    cout<<"Vertices\tDistance from node 0\n";
    for(int i=0;i<v;i++)
    cout<<" "<<i<<"\t\t\t"<<ans[i]<<endl;
    cout<<endl;
    ans=Dijkstra(8);
    cout<<"Vertices\tDistance from node 8\n";
    for(int i=0;i<v;i++)
    cout<<" "<<i<<"\t\t\t"<<ans[i]<<endl;

}
