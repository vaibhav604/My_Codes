#include<bits/stdc++.h>
using namespace std;
template<typename T>
class QusingArray
{
	T *data;
	int size;
	int first;
	int next;
	int capacity;
	public:
		QusingArray(int s)
		{
			data=new T[s];
			next=0;
			first=-1;
			capacity=s;
			size=0;
		}
		int getSize()
		{
			return size;
		}
		bool isEmpty()
		{
			return size==0;
		}	
		void enqueue(T ele)
		{
			if(size==capacity)
			{
				T *newdata=new T[2*capacity];
				int j=0;
				for(int i=first;i<capacity;i++)
				{
					newdata[j++]=data[i];
				}
				for(int i=0;i<first;i++)
				{
					newdata[j++]=data[i];
				}
				
				delete[] data;
				data=newdata;
				first=0;
				next=capacity;
				capacity*=2;
			}
			data[next]=ele;
			next=(next+1)%capacity;
			if(first==-1)
				first=0;
			size++;
		}
		T dequeue()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty";
				return 0;
			}
			T t=data[first];
			first=(first+1)%capacity;
			size--;
			return t;
		}
		T front()
		{
			if(isEmpty())
			{
				cout<<"Queue is Empty";
				return 0;
			}
			return data[first];
		}	
};



int main()
{
	QusingArray<int> q(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
}
