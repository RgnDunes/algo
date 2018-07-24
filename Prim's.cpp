#include <bits/stdc++.h>
#define MAX 100
using namespace std;

bool marked[MAX];
vector< pair<int,int> > adj[MAX];

void prim(int x)
{
	int minCost=0;
	priority_queue <pair<int,int> , vector< pair <int,int> > , greater<pair<int,int> > > Q;
	Q.push(make_pair(0,x));
	
	vector<pair <int,int> > ans;
	pair<int,int> temp;
	while(!Q.empty())
	{
		temp=Q.top();
		Q.pop();
		
		int x=temp.second;
		if(marked[x]==true)
		continue;
		ans.push_back(temp);
		minCost+=temp.first;
		marked[x]=true;
		
		for(int i=0;i<adj[x].size();i++)
		{
			int y=adj[x][i].second;
			if(marked[y]==false)
			Q.push(adj[x][i]);
		}
	}
	cout<<minCost<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<< ans[i].first<<" "<<ans[i].second<<endl;
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	int x,y,weight;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	for(int i=0;i<n;i++)
	marked[i]=false;
	prim(0);
}
