#include<iostream>
#include<string>
using namespace std;
void subsequence(string s,string output)
{
	if(s.size()==0)
	{
		cout<<output<<endl;
		return;
	}
	subsequence(s.substr(1),output);
	subsequence(s.substr(1),output+s[0]);
	
}
int main()
{
	string s;
	cin>>s;
	//string* output=new string[1000];//dynamic allocation
	subsequence(s,"");
	return 0;
}
