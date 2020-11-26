#include<bits/stdc++.h>
using namespace std;

int postfixEval(string str)
{
	stack<int> s;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			s.push(str[i]-'0');
		}
		else
		{
			if(s.size()>=2)
			{
				int n=s.top();s.pop();
				int m=s.top();s.pop();
				switch(str[i])
				{
					case '+':s.push(n+m);
							break;
					case '-':s.push(m-n);
							break;
					case '*':s.push(n*m);
							break;
					case '/':s.push(m/n);
							break;
				}
			}
		}
	}
	if(s.size()>1)
	{
		return -111;
	}
	int ans=s.top();s.pop();
	return ans;
}

int main()
{
	string str="123*+5-";
	if(postfixEval(str)!=(-111))
	{
		cout<<postfixEval(str)<<endl;
	}
	else 
	{
		cout<<"wrong sequence"<<endl;
	}
	
}
