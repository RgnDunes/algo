#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int indeg[MAX];
vector <vector<int> > adj(MAX);
void topo(int n)
{
	string ans="";
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indeg[i]==0)
		{
			q.push(i);
			char temp[5];
			sprintf(temp,"%d",i);
			ans=ans+temp+" ";
		}
	}
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		
		for(int i=0;i<adj[t].size();i++)
		{
			indeg[adj[t][i]]--;
			if(indeg[adj[t][i]]==0)
			{
				q.push(adj[t][i]);
				char temp[5];
				sprintf(temp,"%d",adj[t][i]);
				ans=ans+temp+" ";
			}
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int n,e;
	cin>>n>>e;
	for(int i=0;i<n;i++)
	indeg[i]=0;
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		indeg[y]++;
	}
	topo(n);
}
