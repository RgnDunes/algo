#include <bits/stdc++.h>
using namespace std;

void insert(int *arr,int value,int &n)
{
	if(n==0)
	{
		arr[n++]=value;
		return ;
	}
	arr[n++]=value;
	int ptr=n-1;
	int pptr=(ptr-1)/2;
	while(pptr>=0 && arr[pptr]<value)
	{
		arr[ptr]=arr[pptr];
		ptr=pptr;
		if(ptr-1>=0)
		pptr=(ptr-1)/2;
		else break;
	}
	arr[ptr]=value;
	return ;
	
}
void del(int * arr,int value,int &n)
{
	int ptr=-1;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==value)
		ptr=i;
	}
	if(ptr==-1)
	{
		cout<<"Not found!";
		return ;
	}
	int repl=arr[--n];
	int cptr=ptr*2+1;
	while(cptr<n && arr[cptr])
	{
		if(cptr+1<n && arr[cptr]<arr[cptr+1])
		cptr=cptr+1;
		
		
	}
}

void display(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int value;
    int arr[100];
	int n=0;
    while(1)
    {
            cout<<"1.Insert 2.Delete 3.Display\n";
            int choice ;
			cout<<"Enter your choice: ";
			cin>>choice;
            switch(choice)
            {
                    case 1:cout<<"Value:";cin>>value;insert(arr,value,n);break;
                    case 2:cout<<"Value:";cin>>value;del(arr,value,n);break;
                    case 3:display(arr,n);break;
                    default:exit(0);
            }
    }
}
