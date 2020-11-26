#include<bits/stdc++.h>
using namespace std;

string removeAllDuplicates(string str)
{
	stack<char> s;int i=0;string ns="";
	while(i<str.length())
	{
		if(s.empty() || s.top()!=str[i])
		{
			s.push(str[i++]);
		}
		else
		{
			s.pop();i++;
		}
	}
	if(s.empty())
	{
		return("Empty String");
	}
	while(!s.empty())
	{
		ns= s.top()+ns;s.pop();
	}
	return ns;
}

int main()
{
	string str="careermonk";
	cout<<removeAllDuplicates(str)<<endl;
	str="mississippi";
	cout<<removeAllDuplicates(str)<<endl;
	return 0;	
}
