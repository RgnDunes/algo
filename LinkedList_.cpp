
#include <iostream>
#include <cstdlib>
using namespace std;

struct node{
	node* link;
	int info;
};

node* insert_norm(node *start,int data)
{
	node* new_node=(node *)malloc(sizeof(node));
	node* ptr=start;
	if(start==NULL)
	{
		new_node->info=data;
		new_node->link=NULL;
		start=new_node;
		return start;
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=new_node;
		new_node->info=data;
		new_node->link=NULL;
		return start;
	}
	
}
//void insert_pos(){

int delete_norm(node* start)
{
	node *ptr=start;
	if(ptr==NULL)
	return 0;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}

	int data=ptr->info;	
	ptr=ptr->link;
		return data;
}

void display(node* start)
{
	node* ptr=start;
	if(ptr==NULL)
	cout<<"Nothing to display";
	else
	{
		while(ptr!=NULL)
		{
			cout<<ptr->info<<" ";
			ptr=ptr->link;
		}
	}
	return ;
}	

node* reverse(node* start)
{
	if(start==NULL)
	return start;
	
	else if(start->link==NULL)
	return start;
	
	node* curr=start;
	node* prev=NULL;
	node* other=curr->link;
	
	while(curr!=NULL)
	{
		curr->link=prev;
		if(other==NULL)
		break;
		prev=curr;
		curr=other;
		other=other->link;
	}
	return curr;
}
void revdisp(node* start)
{
	if(!start)
	return ;
	
	revdisp(start->link);
	cout<<start->info<<" ";
	
}
int count(node* start)
{
	int count=0;
	while(start!=NULL)
	{
		start=start->link;
		count++;
	}
	return count;
	
}
node* kplus1(node*start,int k)
{
	int i=0;
	if(k<0)
	return NULL;
	if(count(start)>=k)
	{
		while( i!=k)
		{
			start=start->link;
			i++;
		}
		return start;
	}
	else 
	return NULL;
}
node* kBlocks(node* start,int k)
{
	node* ptr=start;
	node* newHead=kplus1(start,k-1);
	while(count(ptr)>=k)
	{
		cout<<"Entered second loop\n";
 		node* k_1=kplus1(ptr,k);
 		node* curr=ptr;
		node* prev=NULL;
		node* other=curr->link;
		
		while(curr!=k_1)
		{
			cout<<"Entered first loop\n";
			curr->link=prev;
			if(other==k_1)
			break;
			prev=curr;
			curr=other;
			other=other->link;
		}
		curr
		ptr=k_1;
	}
	return newHead;
}
int main()
{
	node * start=NULL;node* temp=NULL;
	int data,pos,choice;
	while(1)
	{	
		cout<<"Enter your choice ";
		cin>>choice;
		switch(choice)
		{
			case 2:
				cout<<delete_norm(start);
				break;
			case 1:
				cout<<"Enter the data to insert ";
				cin>>data;
				start=insert_norm(start,data);
				break;
 			case 3:start=reverse(start);break;
  	        case 4:display(start);
  	        cout<<endl;
  	    	 	  break;          
			case 5:revdisp(start);
				 cout<<endl;
				 break;         
			case 7:cout<<"Size: "<<count(start)<<endl;break; 
			case 8:cout<<"Enter k: ";cin>>pos;cout<<"The k+1 node is: ";temp=kplus1(start,pos);
				 				if(temp!=NULL)cout<<temp->info;else cout<<"-1\n";break;   
			case 9:cout<<"Enter k: ";cin>>pos;start=kBlocks(start,pos);break;
            case 6:exit(0);
		}
	}
}
