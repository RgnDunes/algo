#include <bits/stdc++.h>
using namespace std;

struct node
{
	node* lptr;
	node* rptr;
	int data;
	int height;
	
	node()
	{
		lptr=NULL;
		rptr=NULL;
		height=1;
	}
};

int height(node* tree)
{
	if(tree==NULL)
	return 0;
	
	else 
	return 1+max(height(tree->lptr),height(tree->rptr));
}

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

node* leftRot(node* p)
{
	node* q=p->rptr;
	node* hold=q->lptr;
	
	q->lptr=p;
	p->rptr=hold;
	return q;
}

node* rightRot(node* p)
{
	node* q=p->lptr;
	node* hold=q->rptr;
	
	q->rptr=p;
	p->lptr=hold;
	return q;
}

int getBalance(node* tree)
{
	if(tree==NULL)
	return 0;
	
	else 
	return height(tree->lptr)-height(tree->rptr);
}

node* insert(node* tree,int data)
{
	if(tree==NULL)
	{
		node* neww=new node();
		neww->lptr=NULL;
		neww->lptr=NULL;
		neww->data=data;
		neww->height=1;
		return neww;
	}
	if(data<tree->data)
        tree->lptr=insert(tree->lptr,data);
        
	else if(data>=tree->data)
		 tree->rptr=insert(tree->rptr,data);
		 
    tree->height=1+max(height(tree->lptr),height(tree->rptr));
    
    int bal= getBalance(tree);
    
    if(bal>1 && data<tree->lptr->data)
    {
    	return rightRot(tree);
	}
	else if(bal<-1 && data>tree->rptr->data)
	{
		return leftRot(tree);
	}
	
	else if(bal<-1 && data<tree->rptr->data)
	{
		tree->rptr= rightRot(tree->rptr);
		return leftRot(tree);
	}
	else if(bal>1 && data>tree->lptr->data)
	{
		tree->lptr= leftRot(tree->lptr);
		return rightRot(tree);
	}
	return tree;
}

node* findMin(node* tree)
{
	while(tree->lptr!=NULL)
	tree=tree->lptr;
	
	return tree;
}

node* del(node* tree,int data)
{
	if(tree==NULL)
	return tree;
	
	if(data < tree->data)
	tree->lptr=del(tree->lptr,data);
	
	else if(data>tree->data)
	tree->rptr=del(tree->rptr,data);
	
	else if(data==tree->data)
	{
		if(tree->lptr==NULL)
		{
			tree=tree->rptr;
			return tree;
		}
		else if(tree->rptr==NULL)
		{
			tree=tree->lptr;
			return tree;
		}
		else 
		{
			node* temp=findMin(tree->rptr);
			tree->data=temp->data;
			tree->rptr=del(tree->rptr,temp->data);
			return tree;
		}
	}
	
	tree->height=1+max(height(tree->lptr),height(tree->rptr));
    
    int bal = getBalance(tree);
    
    if(bal>1 && getBalance(tree->lptr)>=0)
    {
    	return rightRot(tree);
	}
	else if(bal<-1 && getBalance(tree->rptr)<=0)
	{
		return leftRot(tree);
	}
	
	else if(bal<-1 &&  getBalance(tree->rptr)>0)
	{
		tree->rptr= rightRot(tree->rptr);
		return leftRot(tree);
	}
	else if(bal>1 &&  getBalance(tree->lptr)<0)
	{
		tree->lptr= leftRot(tree->lptr);
		return rightRot(tree);
	}
	return tree;
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
int main()
{
	int value;
    node* tree=NULL;
    while(1)
    {
            cout<<"1.Insert 2.Delete 3.inorder 4.Preorder 5.Postorder 6.LevelOrder 7.Exit\n";
            int choice ;
			cout<<"Enter your choice: ";
			cin>>choice;
            switch(choice)
            {
                    case 1:cout<<"Value:";cin>>value;tree=insert(tree,value);break;
                    case 2:cout<<"Value:";cin>>value;
					while(search(tree,value)){
						tree=del(tree,value);
					}break;
                    case 3:indisp(tree);cout<<endl;break;
                    case 4:predisp(tree);cout<<endl;break;
                    case 5:postdisp(tree);cout<<endl;break;
                    case 6:level(tree);cout<<endl;break;
                    case 7:exit(0);
                    default:cout<<"Re-enter!";
            }
    }
}
