#include<iostream>
using namespace std;

int firstindex(int a[],int size, int x)
{
	if(size==0)
	{
		return -1;
	}
	if(x==a[0])
	{
		return 0;
	}
	int t=firstindex(a+1,size-1,x);
	if(t==-1)
	{
		return -1;
	}
	if(t!=-1)
	{
		return t+1;
	}
	
}

int main()
{
	int a[]={5,8,6,2,6,3};
	cout<<firstindex(a,6,6)<<endl;
	return 0;
}
