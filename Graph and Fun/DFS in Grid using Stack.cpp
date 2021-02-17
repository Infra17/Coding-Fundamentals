#include <bits/stdc++.h>
using namespace std;
int R,C;
// Globally declared the variable for number of Row and Column
int ans;
unordered_map<int,int> Value;
// To keep track of the distinct values

class node
{ // So that the stack we are about to design will be objects of node
    public:
    vector<int> Track;
    pair<int,int> index;
    node(){}
    node(int a,int b,vector<int> v)
    {index.first=a;
    index.second=b;
    Track=v;}
};

void ParseTheTracker(vector<int> Tracker)
{
    int sum=0;
    cout<<"A possible path :";
    for(int i=0;i<(int)Tracker.size();i++)
    {cout<<Tracker[i]<<" ";sum+=Tracker[i];}
    cout<<" With the total value :"<<sum;
    cout<<endl;
    if(Value[sum]==0)
    {Value[sum]++;ans++;}
}

int main()
{
    R=3,C=5;
    vector<vector<int>> Grid{{2,9,4,-1,-1},{6,7,0,1,-1},{-1,3,-1,2,2}};
    ans=0;
    vector<int> a;
    a.push_back(Grid[0][0]);
    stack<node> s;
    node n(0,0,a);
    s.push(n);
    while(!s.empty())
    {
        n=s.top();s.pop();
        int i=n.index.first,j=n.index.second;
        if(i==R || j==C) continue;
        if(Grid[i][j]<0) continue;
        if(i==R-1&&j==C-1) {ParseTheTracker(n.Track);continue;}

        if(i+1!=R)
        {
            a=n.Track;a.push_back(Grid[i+1][j]);
            node temp(i+1,j,a);
            s.push(temp);
        }
        if(j+1!=C)
        {
            a=n.Track;a.push_back(Grid[i][j+1]);
            node temp(i,j+1,a);
            s.push(temp);
        }
    }

    cout<<"\nTotal no. of distinct paths to reach end "<<ans;
}

