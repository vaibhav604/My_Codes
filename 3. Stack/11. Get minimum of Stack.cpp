#include <bits/stdc++.h>
using namespace std;

struct myStack
{
	stack<int>s;
	int min;
	void push (int x)
	{
		if(s.empty())
		{
			s.push(x);
			min=x;
			return;
		}
		if(x>=min)
		{
			s.push(x);
		}
		else
		{
			int t=x*2-min;
			s.push(t);
			min=x;
		}	
	}
	void pop()
	{
		if(s.empty())
		{
			cout<<"Stack is Empty"<<endl;
			return;
		}
		if(s.top()>min)
		{
			s.pop();
		}
		else
		{
			int t=s.top();
			min=2*min-t;
			s.pop();
		}
	}
	void getMin()
	{
		if(!s.empty())
		{
			cout<<min<<endl;
		}
		else
		{
			cout<<"Stack is Empty"<<endl;
		}
	}
	void top()
	{
		if(s.empty())
		{
			cout<<"Stack is Empty"<<endl;
			return;
		}
		int t=s.top();
		if(t>min)
		{
			cout<<t<<endl;
		}
		else
		{
			cout<<min<<endl;
		}
			
	}
};

int main()
{
	myStack s;
	s.push(10);
	s.push(20);
	s.push(8);
	s.getMin();
	s.top();
	s.pop();
	s.top();
	return 0;	
}
