#include<bits/stdc++.h>
using namespace std;

int op(int n,int m, char ch)
{
	switch(ch)
	{
		case '+':return(n+m);
		case '-':return(n-m);
		case '*':return(n*m);
		case '/':return(n/m);
	}
}

int precedence(char t)
{
	if(t == '+'||t == '-')
    	return 1;
    else if(t == '*'||t == '/')
    	return 2;
    else
    {
    	return 0;
	}
    
}
int infixEval(string str)
{
	int i;
	stack<int>s1;
	stack<char>s2;
	for(i=0;i<str.length();i++)
	{
		if(str[i]==' ')
		{
			continue;
		}
		else if(str[i]=='(')
		{
			s2.push(str[i]);
		}
		else if(isdigit(str[i]))
		{
			int val=0;
			while(i<str.length() && isdigit(str[i]))
			{
				val=(val*10)+(str[i]-'0');
				i++;
			}
			s1.push(val);
			i--;
		}
		else if(str[i]==')')
		{
			while(!s2.empty() && s2.top() !='(')
			{
				int m=s1.top();s1.pop();
				int n=s1.top();s1.pop();
				char k=s2.top();s2.pop();
				s1.push(op(n,m,k));
			}
			if(!s2.empty())
			{
				s2.pop();
			}
		}
		else
		{
			while(!s2.empty() && precedence(s2.top()) >= precedence(str[i]))
			{
				int m=s1.top();s1.pop();
				int n=s1.top();s1.pop();
				char k=s2.top();s2.pop();
				s1.push(op(n,m,k));
			}
			s2.push(str[i]);
		}
	}
	
	while(!s2.empty())
	{
		int m=s1.top();s1.pop();
		int n=s1.top();s1.pop();
		char k=s2.top();s2.pop();
		s1.push(op(n,m,k));
	}
	int k=s1.top();
	s1.pop();
	return k;	
}

int main()
{
	string str="100/4+12";
	cout<<infixEval(str)<<endl;
	return 0;
}
