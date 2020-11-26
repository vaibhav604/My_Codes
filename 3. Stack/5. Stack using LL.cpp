#include<iostream>
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
class stack
{
	int size;
	node<T> *head;
	public:
		stack()
		{
			size=0;
			head=NULL;
		}
		
		int getSize()
		{
			return size;
		}
		bool isEmpty()
		{
			return size==0;
		}
		void push(T ele)
		{
			node<T>* newNode=new node<T>(ele);
			newNode->next=head;
			head=newNode;
			size++;
		}
		T pop()
		{
			if(head==NULL)
			{
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			T ans=head->data;
			node<T>* temp=head;
			head=head->next;
			delete temp;
			size--;
			return ans;
		}
		T top()
		{
			if(head==NULL)
			{
				cout<<"Stack is empty"<<endl;
				return 0;
			}
			return head->data;
		}
};
//template<typename T>
int main()
{
	stack<char> s1;
	s1.push('a');
	s1.push('s');
	s1.push('d');
	s1.push('f');
	s1.push('g');
	cout<<s1.getSize()<<endl;
	cout<<s1.isEmpty()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.top()<<endl;
}
