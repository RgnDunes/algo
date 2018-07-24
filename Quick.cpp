#include <bits/stdc++.h>
using namespace std;

void quick(int *arr,int lb,int rb)
{
	int l=lb;
	int r=rb-1;
	int pivot=l;
	if(r<=l)
	return ;
	while(l<r)
	{
		if(pivot==l)
		{
			if(arr[pivot]<arr[r])
			r--;
			
			else if(arr[pivot]>=arr[r])
			{
				int temp=arr[r];
				arr[r]=arr[pivot];
				arr[pivot]=temp;
				
				pivot=r;
			}
		}
		else if(pivot==r)
		{
			if(arr[pivot]>arr[l])
			{
				l++;
			}
			else if(arr[pivot]<=arr[l])
			{
				int temp=arr[l];
				arr[l]=arr[pivot];
				arr[pivot]=temp;
				
				pivot=l;
			}
		}
		if(r<=l)
	return ;
	}
	if(r<=l)
	return ;
	quick(arr,l,pivot);
	quick(arr,pivot+1,rb);
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
	quick(arr,0,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
