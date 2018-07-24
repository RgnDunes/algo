#include <bits/stdc++.h>
using namespace std;

struct  node
{
	node* cptr[26];
	bool eof;
};

void insert(node* &tree,string data)
{
	node* ptr= tree;
	for(int i=0;i<data.length();i++)
	{
		int index= data[i]-'a';
		if(ptr==NULL)
		{
			node* neww = new node();
			for(int i=0;i<26;i++)
			neww->cptr[i]=NULL;
			ptr=neww;
		}
		
		if(!ptr->cptr[index])
		{
			node* neww = new node();
			for(int i=0;i<26;i++)
			neww->cptr[i]=NULL;
			ptr->cptr[index]=neww;
		}

		ptr=ptr->cptr[index];
	}
	ptr->eof=true;
}

bool alone(node* tree)
{
	int count=0;
	for(int i=0;i<26;i++)
	{
		if(tree->cptr[i])
		count++;
	}
	if(count==1 && tree->eof==false)
	return true;
	else if(count==0 && tree->eof==true)
	return true;
	else
	return false;
}

int have(node* tree)
{
	for(int i=0;i<26;i++)
	{
		if(tree->cptr[i])
		return 1;
	}
	return 0;
}

int del(node* &tree, string data)
{
	if(tree==NULL)
	{
		return 0;
	}
	
	if(data!="")
	{
		if(tree!=NULL && tree->cptr[data[0]-'a']!=NULL  && del(tree->cptr[data[0]-'a'],data.substr(1)) && tree->eof==false)
		{
			if(!have(tree))
			{
				delete(tree);
				tree=NULL;
				return 1;
			}
			else
			return 0;
		}
		
	}
	if(data=="" && tree->eof)
	{
		if(!have(tree))
		{
			delete(tree);
			tree=NULL;
			return 1;
		}
		else
		{
			tree->eof=false;
			return 0;
		}
	}
	return 0;
}

bool search (node* tree, string data)
{
	node* ptr= tree;
	for(int i=0;i<data.length();i++)
	{
		int index= data[i]-'a';
		if(ptr->cptr[index]==NULL)
		{
			cout<<"Still traverdsing!";
			return false;
		}
		
		else 
		ptr=ptr->cptr[index];
	}
	if(ptr->eof==true)
	return true;
	else 
	{
		cout<<"Not eof";
		return false;
	}
}
void display(node* tree)
{
	if(tree==NULL)
	return ;
	queue <node*> q;
	q.push(tree);
	while(!q.empty())
	{
		node* ptr= q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(ptr->cptr[i])
			{
				cout<<(char)(i+'a')<<" ";
				q.push(ptr->cptr[i]);
			}	
		}
		cout<<endl;
	}
}
int main()
{
	node* tree;
	tree= new node();
	for(int i=0;i<26;i++)
	tree->cptr[i]=NULL;
	
	tree->eof=false;
	int choice;
	string str;
	while(1)
	{
		cout<<"1.Insert 2.Search\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1:cin>>str;insert(tree,str);
				 break;;
		    case 2:cin>>str;search(tree,str)?cout<<"Found\n":cout<<"Not found\n";
		    	 break;
		    case 3:cin>>str;del(tree, str);break;
 	        case 4:display(tree);break;
 	        case 5: exit(0);
   	 		 default: break;
		}
	}
}
