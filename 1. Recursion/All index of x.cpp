#include<iostream>
using namespace std;

int allindex(int a[],int size, int x, int output[])
{
	if(size==0)
	{
		return 0;
	}
	int t=allindex(a+1,size-1,x,output);
	if(x==a[0])
	{
		for(int i=t-1;i>=0;i--)
		{
			output[i+1]=output[i]+1;
		}
		output[0]=0;
		t++;
	}
	else
	{
		for(int i=t-1;i>=0;i--)
		{
			output[i]=output[i]+1;
		}
	}
	return t;
}

int allindex(int a[],int size, int x)
{
	int output[size];
	int n=allindex(a,size,x,output);
	return n;
}

int main()
{
	int a[]={2,3,4,2,3,4};
	cout<<allindex(a,6,5)<<endl;
	return 0;
}
