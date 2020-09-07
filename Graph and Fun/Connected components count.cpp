//problem : Connected components count
//Author : Infra

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
typedef long long int lld;
#define mod 1000000007
using namespace std;

class gr
{
	public:
	int n,co;list<int> *ad;int *v;
	gr(int a)
	{
		n=a;co=0;
		ad= new list<int>[a];
		v= new int[n];
		for(int i=0;i<n;i++)v[i]=0;
	}
	~gr(){delete[] ad;}
	void join(int a,int b)
	{
		ad[a].push_back(b);
		ad[b].push_back(a);
	}
	void count()
	{
		for(int i=0;i<n;i++)
		{
		    cout<<i<<endl;
			if(v[i]==0)
			{dfs(i);co++;}cout<<endl;
		}
		
	}
	void dfs(int a)
	{
		v[a]=1;cout<<a<<" ";
		list<int>::iterator i;
		for(i=ad[a].begin();i!=ad[a].end();++i)
		if(v[*i]==0) dfs(*i);
	}

};
int main()
{
  int v,e,a,b; cin>>v>>e;
  gr g(v);
  for(int i=0;i<e;i++)
  {cin>>a>>b;g.join(a,b);}
  g.count();cout<<g.co;
}
