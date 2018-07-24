#include <bits/stdc++.h>
#define RED 1
#define BLACK 0
using namespace std;

struct node
{
	node* lptr;
	node* rptr;
	int data;
	node* par;
	int color;
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
}

void indisp(node*tree)
{
        if(tree==NULL)
        {
                return;
        }
        indisp(tree->lptr);
        cout<<tree->data<<" ";
        indisp(tree->rptr);
}

void predisp(node*tree)
{
        if(tree==NULL)
                return;

        cout<<tree->data<<" ";
        predisp(tree->lptr);
        predisp(tree->rptr);
}

void postdisp(node*tree)
{
        if(tree==NULL)
                return;

        postdisp(tree->lptr);
        postdisp(tree->rptr);
        cout<<tree->data<<" ";

}
int search(node* tree,int value)
{
	if(tree==NULL)
	return 0;
	
	if(value<tree->data)
    return search(tree->lptr,value);
    
    else if(value>tree->data)
    return search(tree->rptr,value);
    
    return 1;
}

node* BSTinsert(node* tree,node* neww)
{
	if(tree==NULL)
	return neww;
	
	if(neww->data >= tree->data)
	{
		tree->rptr=insert(tree->rptr,neww);
		tree->rptr->par=tree;
	}
	else if(neww->data < tree->data)
	{
		tree->lptr=insert(tree->lptr,neww);
		tree->lptr->par=tree;
	}
	
	return tree;
}

void rightRot(node*& tree, node*& p)
{
	node* q= p->lptr;
	node* hold= q->rptr;
	
	p->lptr=hold;
	if(hold!=NULL)
	hold->par=p;
	
	q->par=p->par;
	if(p!=tree)
	{
		if(p->par->lptr==p)
		p->par->lptr=q;
		
		else
		p->par->rptr=q;
	}
	else
	{
		tree=q;
	}
    p->par=q;
    q->rptr=p;
}

void leftRot(node*& tree,node*& p)
{
	node* q=p->rptr;
	node* hold= q->lptr;
	
	p->rptr=hold;
	if(hold!=NULL)
	hold->par=p;
	
	q->par=p->par;
	
	if(p!=tree)
	{
		if(p->par->lptr==p)
		p->par->lptr=q;
		
		else
		p->par->rptr=q;
	}
	else
	{
		tree=q;
	}
	q->lptr=p;
	p->par=q;
}

void fixViolation(node*& tree, node*& neww)
{
	node* 
}

node* insert(node* tree,int data)
{
	node* neww=new node();
	neww->lptr=neww->par=neww->rptr=NULL;
	neww->data=data;
	neww->color=RED;//
	tree=BSTinsert(tree,neww);//
	fixViolation(tree,neww);
}

int main()
{
	int value;
    node* tree=NULL;

    while(1)
    {
            cout<<"1.Insert 2.Search 3.inorder 4.Preorder 5.Postorder 6.Level 7.Exit\n";
            int choice ;
			cout<<"Enter your choice: ";
			cin>>choice;
            switch(choice)
            {
                    case 1:cout<<"Value:";cin>>value;tree=insert(tree,value);break;
                    case 2:cout<<"Value:";cin>>value;value=search(tree,value);if(value)cout<<"Found!\n";else cout<<"Not found!\n";break;
                    case 3:indisp(tree);cout<<endl;break;
                    case 4:predisp(tree);cout<<endl;break;
                    case 5:postdisp(tree);cout<<endl;break;
                    case 6:level(tree);cout<<endl;break;
                    case 7:exit(0);break;
					default:cout<<"Enter again: ";break;                
            }
    }
}
