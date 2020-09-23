//It is also Kahn's Algo for Top sort
//In lexiographically sorted manner
//Author : Infra

#include <bits/stdc++.h>
using namespace std;
int visit[1000];
int v,e,a,b;
list<int> *arr;
vector<int> ans;
unordered_map<int,int> in;

bool Kahn()
{
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<v;i++)
    if(in[i]==0){q.push(i);}
    
    while(!q.empty())
    {
        int curr=q.top();
        ans.push_back(curr+1);
        //cout<<curr+1<<" ";
        q.pop();
        
        for(int child:arr[curr])
        {
            in[child]--;
            if(in[child]==0)
            q.push(child);
        }
    }
    
    return ans.size()==v;
    
    
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
    
    if(!Kahn())
    cout<<"NA";
    else
    for(int i:ans)
    cout<<i<<" ";
    
}
