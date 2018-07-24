#include <bits/stdc++.h>
using namespace std;

void bubble(int *arr,int n)
{
	vector<vector <int> > bucket(10);
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(max<arr[i])
		max=arr[i];
	}
	int divider=ceil((max+1)/10.0);
	for(int i=0;i<n;i++)
	{
		int pos=arr[i]/divider;
		bucket[pos].push_back(arr[i]);
	}
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<bucket[i].size();j++)
		{
			cout<<bucket[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0,k=0;i<10;i++)
	{
		sort(bucket[i].begin(),bucket[i].end());
		for(int j=0;j<bucket[i].size();j++)
		{
			arr[k]=bucket[i][j];k++;
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
