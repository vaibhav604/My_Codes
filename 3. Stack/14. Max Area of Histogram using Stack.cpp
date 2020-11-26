#include<bits/stdc++.h>
using namespace std;
int maxArea(int hist[], int n)
{
	int tp=-1,i=0;
	int mx=0;
	int maxtp=0;
	stack<int> s;
	while(i<n)
	{
		if(s.empty() || hist[s.top()]<=hist[i])
		{
			s.push(i++);
		}
		else
		{
			tp=s.top();
			s.pop();
			maxtp=hist[tp]*(s.empty()? i : (i-s.top()-1));
			mx=max(mx,maxtp);
		}
	}
	while(!s.empty())
	{
		tp=s.top();
		s.pop();
		maxtp=hist[tp]*(s.empty()? i : (i-s.top()-1));
		mx=max(mx,maxtp);
	}
	return mx;
	
}
int main()
{
	stack<int> s;
	int hist[]={6,2,5,4,5,1,6},n=7;
	cout<<maxArea(hist,n);
	return 0;	
}
