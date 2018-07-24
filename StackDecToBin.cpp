#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> bin;
	int n;
	cin>>n;
	int temp=n;
	while(temp)
	{
		bin.push(temp%2);
		temp/=2;
	}
	while(!bin.empty())
	{
		cout<<bin.top();
		bin.pop();
	}
}
