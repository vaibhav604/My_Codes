#include<bits/stdc++.h>
using namespace std;


int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
	q.pop();
	q.pop();
	q.pop();
	cout<<q.front()<<endl;
	cout<<q.size()<<endl;
	cout<<q.empty()<<endl;
	
	return 0;
	
}
