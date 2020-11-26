#include<iostream>
#include<climits>
using namespace std;
template<typename T>
class stackUsingArray
{
	T *data;
	int nextIndex;
	int capacity;
	public:
		
	stackUsingArray()
	{
		data=new T[4];
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
	
	void push(T ele)
	{
		if(nextIndex==capacity)
		{
			T* newData=new T[capacity*2];
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
	
	T pop()
	{
		if(isEmpty())
		{
			cout<<"Stack is Empty"<<endl;
			return 0;
		}
		nextIndex--;
		return data[nextIndex];
	}
	
	T top()
	{
		if(isEmpty())
		{
			cout<<"Stack is Empty"<<endl;
			return 0;
		}
		return data[nextIndex-1];
	}
};


int main()
{
	stackUsingArray<char> s;
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	cout<<s.size()<<endl;
	cout<<s.isEmpty()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.top()<<endl;
	//cout<<s.size()<<endl;
	return 0;
}
