#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int q,n,m,p,t,countr=0, countg=0, countr1=0, countg1=0;
	char s[100][100];
	cin>>q;
	int a[q];
	for(int k=0; k<q; k++)
	{
		cin>>n>>m;
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		cin>>s[i][j];
//	}
//	for(int k=0; k<q; k++)
//	{
		for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if((i+j)%2==0)
			{
				if(s[i][j]!='R')
				countr++;
				if(s[i][j]!='G')
				countg1++;
			}
			else
			{
				if(s[i][j]!='R')
				countr1++;
				if(s[i][j]!='G')
				countg++;
			}
		}
		p= countr*3+countg*5;
		t= countr1*3+countg1*5;
		a[k]=min(p,t);
		countr=0, countg=0, countr1=0, countg1=0;
		cout<<min(p,t)<<"\n";
	}
//	for(int i=0; i<q; i++)
//	cout<<a[i]<<endl;
//	return 0;
} 
