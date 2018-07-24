#include <bits/stdc++.h>
using namespace std;

void bubble(int *arr,int n)
{
	int swapped =1;
	for(int i=0;i<n-1 && swapped;i++)
	{
		swapped =0;
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=1;
			}
			cout<<"Hello"<<endl;
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
	bubble(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
