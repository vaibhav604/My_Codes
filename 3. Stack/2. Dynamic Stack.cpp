#include<iostream>
#include<climits>
using namespace std;

class stackUsingArray
{
	int *data;
	int nextIndex;
	int capacity;
	public:
		
	stackUsingArray()
	{
		data=new int[4];
		nextIndex=0;
		capacity=4;
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
			int* newData=new int[capacity*2];
			for(int i=0;i<capacity;i++)
			{
				newData[i]=data[i];
			}
			delete []data;
			data=newData;
			capacity*=2;
			//cout<<"Stack is Full"<<endl;
			//return;
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
};


int main()
{
	stackUsingArray s;
	s.push(11);
	s.push(22);
	s.push(33);
	s.push(44);
	s.push(55);
	cout<<s.size()<<endl;
	//cout<<s.isEmpty()<<endl;
	//cout<<s.pop()<<endl;
	cout<<s.top()<<endl;
	//cout<<s.size()<<endl;
	return 0;
}
