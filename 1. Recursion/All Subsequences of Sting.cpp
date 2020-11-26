#include<iostream>
#include<string>
using namespace std;
int subsequence(string s,string output[])
{
	if(s.size()==0)
	{
		output[0]="";
		return 1;
	}
	int k=subsequence(s.substr(1),output);
	for(int i=0;i<k;i++)
	{
		output[i+k]=output[i]+s[0];
	}
	return 2*k;	
}
int main()
{
	string s;
	cin>>s;
	string* output=new string[1000];//dynamic allocation
	int n=subsequence(s,output);
	for(int i=0;i<n;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}
