#include <iostream>
using namespace std;

int arr[4];	int top1=0,top2=4-1;


void insert(int data,int stack)
{
	if(stack==1)
	{
		if(top2+1==top1-1+1)
		cout<<"\nStack full";
		else 
		{
			arr[top1++]=data;
			cout<<"\nData successfully entered";
		}
	}
	if(stack==2)
	{
		if(top2+1==top1-1+1)
		{
			cout<<"\nStack full";
		}
		else
		{
			arr[top2--]=data;
			cout<<"\nData successfully entered";
		}
	}
}

int deleted(int stack)
{
	if(stack==1)
	{
		if(top1==0)
		{
			cout<<"\nStack is empty";
		}
		else 
		{
			top1--;
			cout<<"\nData deleted: "<<arr[top1];
		}
	}
	if(stack==2)
	{
		if(top2==4-1)
		{
			cout<<"\nStack is empty";
		}
		else 
		{
			top2++;
			cout<<"\nData deleted: "<<arr[top2];
		}
	}
}


int main()
{
	
	int choice=1;
	
	while(choice!=0)
	{
		cout<<"\nEnter 1 for insertion and 2 for deletion";
		cin>>choice;
		if(choice==1)
		{
			int data,stack;
			cout<<"Enter the data and the stack";
			cin>>data>>stack;
			insert(data,stack);
		}
		if(choice==2)
		{
			int stack;
			cout<<"Enter the stack no.";
			cin>>stack;
			deleted(stack);
		}
	}
}
