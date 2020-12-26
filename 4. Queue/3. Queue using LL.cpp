#include<bits/stdc++.h>
using namespace std;
template<typename T>
class node
{
	public:
		T data;
		node<T> *next;
		node(T data)
		{
			this->data=data;
			next=NULL;
		}
};
template<typename T>
class QusingLL
{
	node<T> *head,*tail;
	int size;
	public:
		QusingLL()
		{
			head=NULL;
			tail=NULL;
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
			node<T> *newnode=new node<T>(ele);
			if (head==NULL)
			{
				head=newnode;
				tail=newnode;
			}
			else
			{
				tail->next=newnode;
				tail=newnode;
			}
			size++;
		}
		T front()
		{
			if(isEmpty())
			{
				cout<<"Q is empty"<<endl;
				return 0;
			}
			return head->data;
		}
		T dequeue()
		{
			if(isEmpty())
			{
				cout<<"Q is empty"<<endl;
				return 0;
			}
			T ans=head->data;
			node<T> *t=head;
			head=head->next;
			delete t;
			size--;
			return ans;
		}
};

int main()
{
	QusingLL<int> q;
	q.isEmpty();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	cout<<q.front()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.front()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;
	
	return 0;
	
}
