#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> MatrixMultiplication(vector<vector<int>> mat1,vector<vector<int>> mat2,int v)
{
    vector<vector<int>> Mat(v,vector<int>(v,0));
    for(int i=0;i<v;i++)
    for(int j=0;j<v;j++)
    {
        for(int k=0;k<v;k++)
        Mat[i][j]+=mat1[i][k]*mat2[k][j];
    }
    return Mat;
}

void Addedges(int a, int b,vector<vector<int>> &Adj)
{
    Adj[a][b]=Adj[b][a]=1;
}

int main()
{
    int v=9,ans=0;
    // Numbers of vertices
    vector<vector<int>> Adj(v,vector<int>(v));
    Addedges(1,2,Adj);Addedges(3,2,Adj);Addedges(1,3,Adj);
    Addedges(3,4,Adj);Addedges(4,5,Adj);Addedges(3,5,Adj);
    Addedges(3,7,Adj);Addedges(7,5,Adj);
    Addedges(7,2,Adj);Addedges(4,7,Adj);
    Addedges(0,1,Adj);Addedges(4,6,Adj);

    vector<vector<int>> Adj2(v,vector<int>(v,0)),Adj3(v,vector<int>(v,0));
    Adj2=MatrixMultiplication(Adj,Adj,v);
    Adj3=MatrixMultiplication(Adj2,Adj,v);
    for(int i=0;i<v;i++)
    ans+=Adj3[i][i];

    cout<<"Number Of Triangle in this graph is : "<<ans/6;


}
