//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 struct node {
 	node* lptr,*rptr;
 	char data;
 };

void level(node* tree)
{
	queue<node*> q;
	q.push(tree);
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->lptr!=NULL)
		q.push(temp->lptr);
		
		if(temp->rptr!=NULL)
		q.push(temp->rptr);
	}
	cout<<endl;
}

void preOrder(node* tree)
{
	if(tree==NULL)
	return ;
	
	cout<<tree->data<<" ";
	preOrder(tree->lptr);
	preOrder(tree->rptr);
}

void postOrder(node* tree)
{
	if(tree==NULL)
	return ;

	postOrder(tree->lptr);
	postOrder(tree->rptr);		
	cout<<tree->data<<" ";
}

void inOrder(node* tree)
{
	if(tree==NULL)
	return ;
	cout<<"(";
	inOrder(tree->lptr);
	cout <<tree->data;
	inOrder(tree->rptr);
	cout<<")";		

}

int main()
{
	string postfix;
	cin>>postfix;
	cout<<postfix<<endl;
	stack<node*>s;
	int i=0;
	while(i<postfix.length())
	{
		if(isalpha(postfix[i]))
		{
			node *temp=new node();
			temp->lptr=NULL;
			temp->rptr=NULL;
			temp->data=postfix[i];
			s.push(temp);
		}
		else
		{
			node* oprnd1=s.top();
			s.pop();
			node* oprnd2=s.top();
			s.pop();
			node* optor=new node();
			optor->lptr=oprnd2;
			optor->rptr=oprnd1;
			optor->data=postfix[i];
			s.push(optor);
		}
		i++;
	}	

	while(!s.empty())
	{
		cout<<"Preorder: ";
		preOrder(s.top());
		cout<<endl;
		cout<<"Postorder: ";
		postOrder(s.top());
		cout<<endl;
		cout<<"Inorder: ";
		inOrder(s.top());
		cout<<endl;
		cout<<"Level: ";
		level(s.top());
		s.pop();
		cout<<endl;
	}

}
