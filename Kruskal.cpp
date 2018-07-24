#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int arr[100];
int sz[100];
pair<int, pair<int,int> > p[MAX];
void initialize()
{
	for(int i=0;i<MAX;i++)
	{
		arr[i]=i;
		sz[i]=1;
    }
	
}

int root(int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
	return x;
}

void Union(int x,int y)
{
	int root_x= root(x);
	int root_y=root(y);
	
	if(sz[root_x]>= sz[root_y])
	{
		arr[root_y]=arr[root_x];
		sz[root_x]+=sz[root_y];
	}
	else 
	{
		arr[root_x]=arr[root_y];
		sz[root_y]+=sz[root_x];
	}
}

void kruskal(int e)
{
	sort(p,p+e);
	int sum=0;
	vector <pair <int,int> > ans;
	for(int i=0;i<e;i++)
	{
		int u=p[i].second.first;
		int v=p[i].second.second;
		
		if(root(u)!=root(v))
		{
			sum+=p[i].first;
			ans.push_back(make_pair(u,v));
			Union(u,v);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	cout<<"Path weight: "<<sum;
}

int main()
{
	int n,e;
	cin>>n>>e;
	int x,y,weight;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>weight;
		p[i]=make_pair(weight,make_pair(x,y));
	}
	initialize();

	kruskal(e);
}
