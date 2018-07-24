#include <iostream>
using namespace std;

struct node{
	int data;
	node* link;
};
bool vis[100];

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

	int e;
	cout<<"Enter the number of edges: ";
	cin>>e;
	cout<<"Enter the pair of edges: \n";
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		node* neww= new node();
		neww->data=b;
		neww->link=NULL;
		
		node * ptr= &G[a];
		while(ptr->link!=NULL)
		ptr=ptr->link;
		
		ptr->link=neww;
		cout<<"Succesfully inserted : "<<ptr->link->data<<endl;
		
		node* neww2=new node();
		neww2->data=a;
		neww2->link=NULL;
		
		ptr=&G[b];
		while(ptr->link!=NULL)
		ptr=ptr->link;
		
		ptr->link=neww2;
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
	for(int i=0;i<n;i++)
	vis[i]=false;
	cout<<G[0].data<<" ";
	dfs(G,G[0].data,n);
	for(int i=0;i<n;i++)
	vis[i]=false;
//	bfs(G,G[0].data,n);
	
}
