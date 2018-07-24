#include <bits/stdc++.h>
using namespace std;

int findPos(int *ans,int data,int size)
{
	int i;
	for( i=0;i<size;i++)
	{
		if(data<ans[i])
		break;
	}
	return i;
}

void insert(int *ans,int data,int size)
{
	if(size==0)
	{
		ans[size]=data;
		return ;
	}
	int pos=findPos(ans,data,size);
	
	for(int j=size;j>=pos;j--)
	{
		ans[j]=ans[j-1];
	}
	ans[pos]=data;
}

void insertSort(int *arr,int n)
{
	int ans[n];
	
	for(int i=0;i<n;i++)
	{
		insert(ans,arr[i],i);		
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	insertSort(arr,n);
	
}
