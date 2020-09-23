//Kahn's Algo for Top sort
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000];
int v,e,a,b;
list<int> *arr;
unordered_map<int,int> in;

void Kahn()
{
    queue<int> q;
    for(int i=0;i<v;i++)
    if(in[i]==0)q.push(i);
    
    while(!q.empty())
    {
        int curr=q.front();
        cout<<curr+1<<" ";
        q.pop();
        
        for(int child:arr[curr])
        {
            in[child]--;
            if(in[child]==0)
            q.push(child);
        }
    }
    
}


int main()
{
    cin>>v>>e;
    arr= new list<int>[v];
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        in[b-1]++;
    }
    
    Kahn();
}
