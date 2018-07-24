#include <bits/stdc++.h>
using namespace std;

void count(int *arr,int n)
{
	int C[20];
	
	for(int i=0;i<20;i++)
	C[i]=0;
	
	for(int i=0;i<n;i++)
	C[arr[i]]++;
	
	for(int i=1;i<20;i++)
	C[i]=C[i-1]+C[i];
	
	int ans[n]={0};
	for(int i=0;i<n;i++)
	{
		ans[C[arr[i]]-1]=arr[i];
		C[arr[i]]--;
	}
	
	for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
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
	count(arr,n);
	
}
