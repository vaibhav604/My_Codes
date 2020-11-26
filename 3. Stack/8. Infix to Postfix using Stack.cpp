#include <iostream>
#include <bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;


int getPriority(char ch)
{
	
	switch(ch)
	{
		case '+' :	
		case '-' :	return 1;
					break;
		case '*' :	
		case '/' :	return 2;
					break;

		case '^' :	return 3;
					break;

		default  :  return 0 ;
					break ;

	}
}
string infixToPostfix(string s)
{
	stack<char>st;
	string ans="";
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		char c=s[i];
		if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		{
			ans=ans+c;
		}
		else if(c==')')
		{
			while(st.top() !='(' && (!st.empty()))
			{
				ans=ans+st.top();
				st.pop();
			}
			if(st.top()=='(' && (!st.empty())) st.pop();
		}
		else
		{
			while((!st.empty()) && getPriority(st.top()) >= getPriority(c) && c !='(')
			{
				ans=ans+st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty())
	{
		ans=ans+st.top();
		st.pop();
	}
	return ans;
}

int main()
{
	string str = "(A+B)/(C+D)";
	cout<<infixToPostfix(str)<<endl;
	return 0;	
}
