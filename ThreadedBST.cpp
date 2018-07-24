#include <bits/stdc++.h>
#define THREAD 1
#define LINK 0
using namespace std;

struct node{
	node* lptr;
	node* rptr;
	bool ltag;
	bool rtag;
	int data;
};

node* inp(node* ptr)
{
	if(ptr->ltag==1)
	return ptr->lptr;
	
	ptr=ptr->lptr;
	while(ptr->rtag==0)
	ptr=ptr->rptr;
	
	return ptr;
}
node* ins(node* ptr)
{
	
	if(ptr->rtag==1)
	return ptr->rptr;
	
	ptr=ptr->rptr;//
	
	while(ptr->ltag==0)
	ptr=ptr->lptr;
	
	return ptr;
}

void inorder(node* tree)
{
	if(tree==NULL)
	{
		cout<<"Empty!\n";
		return ;
	}
	
	while(tree->lptr!=NULL )
	tree=tree->lptr;
	
	while(tree!=NULL)
	{
		cout<<tree->data<<" ";
		tree=ins(tree);//
	}
	cout<<endl;
}

node* insert(node* tree, int value)
{
	if(tree==NULL)
	{
		node* neww=new node();
		neww->ltag=1;
		neww->rtag=1;
		neww->data=value;
		neww->lptr=NULL;
		neww->rptr=NULL;
		return neww;
	}
	node* ptr=tree;
	while(1)
	{
		if(value<ptr->data && ptr->lptr!=NULL&& ptr->ltag==0)
		{
			ptr=ptr->lptr;
		}
		else if(value >= ptr->data && ptr->rptr!=NULL && ptr->rtag==0)
		{
			ptr=ptr->rptr;
		}
		else 
		break;
	}
	
	node* neww=new node();
	neww->ltag=1;
	neww->rtag=1;
	neww->data=value;
	neww->lptr=NULL;
	neww->rptr=NULL;
	
	if(value<ptr->data)
	{
		neww->lptr=ptr->lptr;
		neww->rptr=ptr;
		ptr->ltag=0;
		ptr->lptr=neww;
	}
	else if(value>=ptr->data)
	{
		neww->lptr=ptr;
		neww->rptr=ptr->rptr;
		ptr->rtag=0;
		ptr->rptr=neww;
	}
	return tree;
}

node* search(node* tree,int value)
{
	
}
int doubleCase=0;
node* doublePtr= NULL;
int doubleData =-1;
node* del(node* tree,int value)
{
	
	if(tree==NULL)
	{
		cout<<"Empty"<<endl;
		return tree;
	}
	
	node* par=NULL;
	node* ptr=tree;
	if(tree->data==value)
	{
		cout<<"Root to be deleted!\n";
		if(tree->lptr==NULL && tree->rptr==NULL)
		{
			return NULL;
		}
		else if(tree->lptr==NULL)
		{
			node* temp=tree;
			node* succ=ins(tree);
			succ->lptr=tree->lptr;
			tree=tree->rptr;
			delete(temp);
		}
		else if(tree->rptr==NULL)
		{
			node* temp=tree;
			node* pred=inp(tree);
			pred->rptr=tree->rptr;
			tree=tree->lptr;
			delete(temp);
		}
		else
		{
			node* temp=ins(tree);
			//Storing the value for future use
			doubleCase =1;
			doublePtr= ptr;
			doubleData= temp->data;
			//Now we will call delete once more but with the value as that of the inorder successo
			value =temp->data;
			goto Outsider;
		}
	}
	else
	{
		Outsider:
		par=tree;
		while(1)
		{
			if(value< ptr->data && ptr->lptr!=NULL && ptr->ltag!=1)
			{
				par=ptr;
				ptr=ptr->lptr;
			}
			else if(value >ptr->data && ptr->rptr!=NULL && ptr->rtag!=1)
			{
				par=ptr;
				ptr=ptr->rptr;
			}
			else if(value==ptr->data)
			{
				break;
			}
			else
			{
				cout<<"Not found\n";
				return tree;
			}
		}
		cout<<"Parent: "<<par->data<<"Found: "<<ptr->data<<endl;
		
		if(ptr->ltag==1&& ptr->rtag==1)
		{
			if(par->lptr==ptr)
			{
				par->lptr=ptr->lptr;
				par->ltag=1;
				delete(ptr);
			}
			else if(par->rptr==ptr)
			{
				par->rptr=ptr->rptr;
				par->rtag=1;
				delete(ptr);
			}
		}
		else if(ptr->rtag==0 && ptr->ltag==1)
		{
			if(par->lptr==ptr)
			{
				node* temp=ins(ptr);
				temp->lptr=ptr->lptr;
				par->lptr=ptr->rptr;
				delete(ptr);
			}
			else if(par->rptr==ptr)
			{
				node* temp=ins(ptr);
				temp->lptr=ptr->lptr;
				par->rptr=ptr->rptr;
				delete(ptr);
			}
		}
		else if(ptr->ltag==0 && ptr->rtag==1)
		{
			if(par->lptr==ptr)
			{
				node* temp=inp(ptr);
				temp->rptr=ptr->rptr;
				par->lptr=ptr->lptr;
				delete(ptr);
			}
			else if(par->rptr==ptr)
			{
				node* temp=inp(ptr);
				temp->rptr=ptr->rptr;
				par->rptr=ptr->lptr;
				delete(ptr);
			}
		}
		else if(ptr->ltag==0 && ptr->rtag==0)
		{
			node* temp=ins(ptr);
			//Storing the value for future use
			doubleCase =1;
			doublePtr = ptr;
			doubleData = temp->data;
			//Now we will call delete once more but with the value as that of the inorder successor
			value= temp->data;
			goto Outsider;
		}
	}
	if(doubleCase ==1)//In case a node with both Non - NULL pointers was deleted
	{
		doublePtr->data=doubleData;
	}
	return tree;
	
}

int main()
{
 	int value;
    node* tree=NULL;
    node** arr;
	cout<<"1.Insert 2.Search 3.Delete 4.inorder\n";

    while(1)
    {
            int choice ;
			cout<<"Enter your choice: ";
			cin>>choice;
            switch(choice)
            {
                case 1:cout<<"Value:";cin>>value;tree=insert(tree,value);break;
                case 2:cout<<"Value:";cin>>value;search(tree,value);break;
                case 3:cout<<"Value:";cin>>value;tree=del(tree,value);break;
                case 4:inorder(tree);break;
                case 5:exit(0);break;
                default:cout<<"Reenter\n";break;
            }
       }
}
