#include<iostream>
using namespace std;

int lastindex(int a[],int size, int x)
{
	if(size==0)
	{
		return -1;
	}
	if(x==a[size-1])
	{
		return size-1;
	}
	int t=lastindex(a,size-1,x);
	if(t==-1)
	{
		return -1;
	}
	if(t!=-1)
	{
		return t;
	}
	
}

int main()
{
	int a[]={5,8,2,2,6,3};
	cout<<lastindex(a,6,2)<<endl;
	return 0;
}
