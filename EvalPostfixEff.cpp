///Can evaluate multi digit as well as in decimal also


#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <cstdlib>
using namespace std;

float operate(float a,float b,char ch)
{
	switch(ch)
	{
		case '*':cout<<a<<"*"<<b <<endl; return a*b;
		case '-':cout<<a<<"-"<<b <<endl; return a-b;
		case '+':cout<<a<<"+"<<b <<endl; return a+b;
		case '/':cout<<a<<"/"<<b <<endl; return a/b;
		case '^':cout<<a<<"^"<<b <<endl; return pow(a,b);
	}
}

int main()
{
	string exp;
	stack<float> s;			//If the number in the stack is a decimal point 
	getline(cin,exp);
	exp.append("#");
	int i=0,j=0;
	int tempi;char temps[4];
	while(exp[i]!='#')
	{
		if(isdigit(exp[i]))
		{
			while(!isspace(exp[i]))				//For multi digit integers
			{
				temps[j++]=exp[i];			
				i++;
			}
		
			tempi=atoi(temps);			//Converting extracted string into integer
			s.push(tempi);
			for(int a;a<4;a++)			//Emptying residual values of temps
			temps[a]='\0';
			j=0;
		}
		if(ispunct(exp[i]))
		{
			float a=s.top();    //If the number in the stack is a decimal point 
			s.pop();
			float b=s.top();	//If the number in the stack is a decimal point 
			s.pop();
			s.push(operate(b,a,exp[i]));
			i++;
		}
		if(isspace(exp[i]))				//Expression can include any no. of spaces
		i++;
	}
	cout<<s.top();
}
