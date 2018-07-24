#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	cin>>str;
	stack<char> s;
	for(int i=0;i<str.length();i++)
	{
	   s.push(str[i]);
	}
	int i;
	for( i=0;i<str.length();i++)
	{
		if(s.top()!=str[i])
			 {
			 cout<<"Not a pallindrome!";
			 break;
			 }
			 
	    s.pop();
	}
	if(i==str.length())
	cout<<"Pallindrome";
	
	return 0;
}
