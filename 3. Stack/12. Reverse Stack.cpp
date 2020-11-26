#include<iostream>
#include<climits>
using namespace std;

class stackUsingArray
{
	int *data;
	int nextIndex;
	int capacity;
	public:
		
	stackUsingArray(int totalsize)
	{
		data=new int[totalsize];
		nextIndex=0;
		capacity=totalsize;
	}
	
	int size()
	{
		return nextIndex;
	}
	
	bool isEmpty()
	{
		return nextIndex==0;
	}
	
	void push(int ele)
	{
		if(nextIndex==capacity)
		{
			cout<<"Stack is Full"<<endl;
			return;
		}
		data[nextIndex]=ele;
		nextIndex++;
	}
	
	int pop()
	{
		if(isEmpty())
		{
			cout<<"Stack is Empty"<<endl;
			return INT_MIN;
		}
		nextIndex--;
		return data[nextIndex];
	}
	
	int top()
	{
		if(isEmpty())
		{
			cout<<"Stack is Empty"<<endl;
			return INT_MIN;
		}
		return data[nextIndex-1];
	}
	
	
	void insertAtBottom(stackUsingArray* s, int data)
	{
		if(s->isEmpty())
		{
			s->push(data);
			return;
		}
		int t=s->pop();
		insertAtBottom(s,data);
		s->push(t);
	}
	void reverseStack(stackUsingArray* s)
	{
		if(s->isEmpty())
		{
			return;
		}
		int data=s->pop();
		reverseStack(s);
		insertAtBottom(s,data);
	}
	
	
	//Without Extra Space in LL manner
	/*void reverseStack(stackUsingArray* s)
	{
		if(s->isEmpty())
		{
			return;
		}
		reverseStack *prev,*succ,*curr;
		prev->nextIndex=NULL;
		succ=curr=s.top();
		curr=curr->nextIndex;
		while(curr!=NULL;)
		{
			succ=curr->next;
			curr->next=prev;
			prev=curr;
			curr=succ;
		}
		top=prev;
	}*/

};




int main()
{
	stackUsingArray s(4);
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.reverseStack(&s);
	for(int i=0;i<4;i++)
		cout<<s.pop()<<endl;
	return 0;
}
