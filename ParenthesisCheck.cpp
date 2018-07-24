#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	string exp;
	stack<char> s;			
	getline(cin,exp);
	exp.append("#");
	int i=0,j=0;
	s.push('@');       //When the stack is empty then s.top() returns something farzi so the program acts weirdly...So this '@' is there 
					   //so that the stack is never empty
	while(exp[i]!='#')			//We don't have to compare i everytime
	{
		if(exp[i]=='(')
		{
			s.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			if(s.top()!='(')			//This shows that ) has been inserted before ( and hence unbalanced
			{
				cout<<"Unbalanced";exit(0);
			}
			else				//Pop out the '(' pair of ')'
			s.pop();
		}
		i++;
	}
	if(s.top()=='@')			//Initial condition.... i.e. everything took place normally
	cout<<"Balanced";
	
	
	return 0;
}
