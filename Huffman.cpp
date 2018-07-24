#include <bits/stdc++.h>
#include <queue>
#include <functional>
using namespace std;

struct node{
	node* lptr;
	node* rptr;
	int data;
	char key;
	
	node(int d)
	{
		lptr=NULL;rptr=NULL;
		data=d;
		key='e';
	}
};

void printCodes(node* tree, string str)
{
    if (!tree)
        return;
 
    if (tree->key != 'i')
        cout << tree->data << ": " << str << "\n";
 
    printCodes(tree->lptr, str + "0");
    printCodes(tree->rptr, str + "1");
}

void levelOrder(node* tree)
{
	queue<node*> q;
	q.push(tree);
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		cout<<temp->data<<" "<<temp->key<<"\n";
		if(temp->lptr!=NULL && temp->lptr->key!='e')
		q.push(temp->lptr);
		
		if(temp->rptr!=NULL && temp->rptr->key!='e')
		q.push(temp->rptr);
	}
	cout<<endl;
}

bool compare(node* a,node* b)
{
	return a->data < b->data;
}

int main()
{
	int arr[]={22,5,11,19,2,11,25,5};
	int n=8;
	node* seg[n];
	for(int i=0;i<n;i++)
	{
		seg[i]=new node(arr[i]);
	}
	vector< node* >p;
	
	for(int i=0;i<n;i++)
	p.push_back(seg[i]);
	
	sort(p.begin(),p.end(),compare);
	node* tree=NULL;
	while(p.size()!=1)
	{
		node* a=p[0];
		node* b=p[1];
		node* neww = new node(a->data+b->data);
		neww->lptr=a;
		neww->rptr=b;
		neww->key='i';
		if(!p.empty())
		p.erase(p.begin());
		
		if(!p.empty())
		p.erase(p.begin());
		
		p.push_back(neww);
		sort(p.begin(),p.end(),compare);

	}
	tree= p[0];
	levelOrder(tree);
	
	printCodes(tree,"");
	
	
}
