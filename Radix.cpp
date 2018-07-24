#include <bits/stdc++.h>
using namespace std;

int digit(int n,int pos)
{
	int exp=pow(10,pos-1);
	n/=exp;
 
 	return n%10;
}

void radix(int *arr,int n)
{
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(max<arr[i])
		max=arr[i];
	}
	int pass=0;
	while(max!=0)
	{
		max/=10;
		pass++;
	}
	queue <int> base[10];
	for(int i=0;i<pass;i++)
	{
		for(int j=0;j<n;j++)
		{
			base[digit(arr[j],i+1)].push(arr[j]);
		}
	
		for(int j=0,k=0;j<10;j++)
		{
			while(!base[j].empty())
			{
				arr[k]=base[j].front();base[j].pop();k++;
			}
		}

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
	radix(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
