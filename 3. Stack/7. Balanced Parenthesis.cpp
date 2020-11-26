#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	stack<char> s;
	char arr[10000];
	cin.getline(arr,10000);
	int i=0;
	while(arr[i]!=0)
	{
		if(arr[i]=='{' || arr[i]=='(' || arr[i]=='[')
		{
			s.push(arr[i]);
		}
		else if(arr[i]=='}')
		{
			char temp=s.top();
			if(temp=='{')
			{
				s.pop();
			}
			else 
			{
				cout<<"false"<<endl;
				return 0;
			}
		}
		else if(arr[i]==']')
		{
			char temp=s.top();
			if(temp=='[')
			{
				s.pop();
			}
			else 
			{
				cout<<"false"<<endl;
				return 0;
			}
		}
		else if(arr[i]==')')
		{
			char temp=s.top();
			if(temp=='(')
			{
				s.pop();
			}
			else 
			{
				cout<<"false"<<endl;
				return 0;
			}
		}
		i++;
	}
	if(s.empty())
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}
