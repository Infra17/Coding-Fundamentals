#include <bits/stdc++.h>
using namespace std;
int n,*v,a,b,*subsetsum,Total;
vector<int> *Adj;

int CountValueDFS(int a,int s)
{
	subsetsum[a]+=v[a];
	for(auto i:Adj[a]) if(i!=s) subsetsum[a]+=CountValueDFS(i,a);
	return subsetsum[a];
}

int main()
{
	cin>>n;
	int ;
	v=new int[n];
	for(int i=0;i<n;i++) cin>>v[i];
	subsetsum= new int[n];
	for(int i=0;i<n;i++) subsetsum[i]=0;
	Adj=new vector<int>[n];
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b; a--;b--;
		Adj[a].push_back(b);
		Adj[b].push_back(a);
	}
	Total=CountValueDFS(0,0);
	//for(int i=0;i<n;i++) cout<<subsetsum[i]<<" "; cout<<endl;
	int M=INT_MAX;
	for(int i=0;i<n;i++) if(Total>=2*subsetsum[i]&&M>Total-2*subsetsum[i]) M=Total-2*subsetsum[i];
	cout<<M;
}



/*
Cut the tree
(Hackerrank problem)
There is an undirected tree where each vertex is numbered from  to , and each contains a data value. The sum of a tree is the sum of all its nodes' data values. If an edge is cut, two smaller trees are formed. The difference between two trees is the absolute value of the difference in their sums.
Given a tree, determine which edge to cut so that the resulting trees have a minimal difference between them, then return that difference.

The minimum absolute difference is .
Note: The given tree is always rooted at vertex .
Function Description
Complete the cutTheTree function in the editor below.
cutTheTree has the following parameter(s):
int data[n]: an array of integers that represent node values
int edges[n-1][2]: an 2 dimensional array of integer pairs where each pair represents nodes connected by the edge
Returns
int: the minimum achievable absolute difference of tree sums
Input Format:
The first line contains an integer , the number of vertices in the tree.
The second line contains  space-separated integers, where each integer  denotes the  data value, .
Each of the  subsequent lines contains two space-separated integers that describe edge  in tree .
 
Sample Input
STDIN                  			     Function
-----                     			  --------
6                           			data[] size n = 6
100 200 100 500 100 600    	 data = [100, 200, 100, 500, 100, 600]
1 2                        		 edges = [[1, 2], [2, 3], [2, 5], [4, 5], [5, 6]]
2 3
2 5
4 5
5 6
 
Sample Output
400
*/
