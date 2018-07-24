#include <iostream>
#include<queue>
#include <climits>
#define INF INT_MAX//INT_MAX is predefined in library

using namespace std;

struct node{
	int data;
	node* link;
};
bool vis[100];

void topologicalSort(node G[],int n,int indeg[])
{
	string topo="";
	queue<int>q;
	
	for(int i=0;i<n;i++)
	{
		if(!indeg[i])
		{
			q.push(i);
			char temp[5];//Don't declare this as a string or it won't work
			sprintf(temp,"%d",i);//Converting int to string
			topo.append(temp);
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		node* ptr= &G[u];
		while(ptr->link!=NULL)
		{
			indeg[ptr->link->data]--;
			if(indeg[ptr->link->data]==0)
			{
				q.push(ptr->link->data);
				char temp[5];//Don't declare this as a string or it won't work
				sprintf(temp,"%d",ptr->link->data);//Converting int to string
			    topo.append(temp);
			}
		}
	}
	cout<<"Topological Sort: "<<topo<<endl;
}

void dfs(node G[],int s,int n)
{
	vis[s]=true;
	node* ptr=&G[s];
	while(ptr->link!=NULL)
	{
		if(vis[ptr->link->data]==false)
		{
			cout<<ptr->link->data<<" ";
			dfs(G,ptr->link->data,n);
		}
	 		ptr=ptr->link;
	}
}

void bfs(node G[],int s,int n)
{
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		node* ptr=&G[t];
		while(ptr->link!=NULL)
		{
			if(!vis[ptr->link->data])
			{
				vis[ptr->link->data]=true;
				cout<<ptr->link->data<<" ";
				q.push(ptr->link->data);
			}
			ptr=ptr->link;
		}
	}
}

int main()
{
	
	int n;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	node G[n];
	for(int i=0;i<n;i++)
	{
		G[i].data=i;
		G[i].link=NULL;
	}
	int indeg[n]={0}; 
	int e;
	cout<<"Enter the number of edges: ";
	cin>>e;
	cout<<"Enter the pair of edges: \n";
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		//Only for directed graph
		node* neww= new node();
		neww->data=b;
		neww->link=NULL;
		
		node * ptr= &G[a];
		while(ptr->link!=NULL)
		ptr=ptr->link;
		
		ptr->link=neww;
		
		indeg[b]++;
		cout<<"Succesfully inserted : "<<ptr->link->data<<endl;
		
		//If the graph is undirected
   		node* neww2=new node();
		neww2->data=a;
		neww2->link=NULL;
		
		ptr=&G[b];
		while(ptr->link!=NULL)
		ptr=ptr->link;
		
		ptr->link=neww2;
		
		indeg[a]++;
		cout<<"Succesfully inserted : "<<ptr->link->data<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		node* ptr=&G[i];
		cout<<G[i].data<<": ";
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
			cout<<ptr->data<<" ";
		}
		cout<<endl;
	}
	//DFS
	
	for(int i=0;i<n;i++)
	vis[i]=false;
	cout<<"DFS: ";
	for(int i=0;i<n;i++)//To cover even the disconnected elements
	{
		if(!vis[i])
		{
			cout<<G[i].data<<" ";
			dfs(G,G[i].data,n);
		}
	}
	cout<<"BFS: ";
	for(int i=0;i<n;i++)
	vis[i]=false;
	for(int i=0;i<n;i++)//Toc cover even the disconnected elements
	{
		if(!vis[i])
		{
			cout<<G[i].data<<" ";
			bfs(G,G[i].data,n);
		}
	}
	
}
