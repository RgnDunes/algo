//Can evaluate only single digit... 

#include<iostream>
#include<stack>
#include <string>
using namespace std;

int operate(int a,int b,char ch)
{
	switch(ch)
	{
		case '*':cout<<a<<"*"<<b <<endl; return a*b;
		case '-':cout<<a<<"-"<<b <<endl; return a-b;
		case '+':cout<<a<<"+"<<b <<endl; return a+b;
		case '/':cout<<a<<"/"<<b <<endl; return a/b;
		
	}
}

int main()
{
	stack <char> s;
	string str;
	cin>>str;
	str.append("#");
	int i=0;
	while(str[i]!='#')
	{
		if(isdigit(str[i]))
		{
			s.push(str[i]);
			i++;
		}
		else if(ispunct(str[i]))
		{
			char a=s.top();
			s.pop();
			char b=s.top();
			s.pop();
			s.push(char(operate(b-'0',a-'0',str[i])+'0'));
			i++;
		}
	}
	cout<<(int)(s.top()-'0');
}
