#include <bits/stdc++.h>
using namespace std;

struct node
{
	node* lptr;
	node* rptr;
	int data;
};

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

node* insert(node* tree,int data)
{
	if(tree==NULL)
	{
		node* neww=new node();
		neww->lptr=NULL;
		neww->lptr=NULL;
		neww->data=data;
		return neww;
	}
	if(data<tree->data)
        tree->lptr=insert(tree->lptr,data);
        
	else if(data>=tree->data)
		 tree->rptr=insert(tree->rptr,data);

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
    node** arr;

    while(1)
    {
            cout<<"1.Insert 2.Delete 3.inorder 4.Preorder 5.Postorder\n";
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
                    default:exit(0);
            }
    }
}
