#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;
	int stock[]={10,35,45,33,78,45,8,52},n=8;
	int span[n],p=0;
	for(int i=0;i<n;i++)
	{
		while(!s.empty() && stock[s.top()]<stock[i])
		{
			s.pop();
		}
		if(s.empty())
		{
			p=-1;
		}
		else
		{
			p=s.top();
		}
		span[i]=i-p;
		s.push(i);
	}
	for(int i=0;i<n;i++)
	{
		cout<<span[i]<<" ";
	}
	
}
